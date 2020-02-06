//
//  Core.cpp
//  pb-receiver-touch
//
//  Created by Valentin Dufois on 2019-11-19.
//

#include "../Common/Structs/Body.hpp"

#include "Core.hpp"

Core::Core() {
	_socket = new pb::network::Socket();
	_socket->delegate = this;

	_browser = new pb::network::Browser();

	_browser->onReceive = [&] (const pb::network::Endpoint &remote) {
		if(_socket->getStatus() != pb::network::SocketStatus::ready) {
			_socketMutex.lock();
			_socket->connectTo(remote.ip, pb::network::serverPortReceiver);
			_socketMutex.unlock();
		}
	};

	_browser->startBrowsing(pb::network::discoveryPortReceiver);
}

Core::~Core()
{
	if(_socket != nullptr) {
		_socket->close();
		delete _socket;
	}

	_browser->stopBrowsing();
	delete _browser;

	pb::network::Engine::instance()->stopContext();
}


// MARK: - TouchDesigner handles

void
Core::getGeneralInfo(CHOP_GeneralInfo* ginfo, const OP_Inputs* inputs, void* reserved1)
{
	// Set our parameters

	// This will cause the node to cook every frame
	ginfo->cookEveryFrameIfAsked = true;
	ginfo->cookEveryFrame = true;

	// Note: To disable timeslicing you'll need to turn this off, as well as ensure that
	// getOutputInfo() returns true, and likely also set the info->numSamples to how many
	// samples you want to generate for this CHOP. Otherwise it'll take on length of the
	// input CHOP, which may be timesliced.
	ginfo->timeslice = false;
}

bool
Core::getOutputInfo(CHOP_OutputInfo* info, const OP_Inputs* inputs, void* reserved1)
{
	// Since we are outputting a timeslice, the system will dictate
	// the numSamples and startIndex of the CHOP data
	info->numSamples = 1;
	info->startIndex = 0;

	// We are about to execute, get a copy of the bodies
	// Did we receive any bodies from the network ?
	_bodiesBufferMutex.lock();

	if(_bodiesBuffer.size() > 0) {
		// We received informations, copy the buffer and clear it
		clearTempBodies();

		for(std::pair<pb::bodyUID, pb::Body *> pair: _bodiesBuffer) {
			// Check if the body is valid
			if(!pair.second->isValid) {
				// Invalid body, ignore and erase.
				delete pair.second;
				continue;
			}

			_tempBodies.push_back(pair.second);
		}
		_bodiesBuffer.clear();
	}

	_bodiesBufferMutex.unlock();

	// Set the number of channels
	_outputPositions = inputs->getParInt("Pboutputpositions");
	_outputOrientations = inputs->getParInt("Pboutputorientations");
	_outputConfidences = inputs->getParInt("Pboutputconfs");

	info->numChannels = 1 + (int)_tempBodies.size() * getChannelCountByBody();

	_indexMutex.lock();

	return true;
}

void
Core::getChannelName(int32_t index, OP_String *name, const OP_Inputs* inputs, void* reserved1)
{
	// First channel is the number of bodies
	if(index == 0) {
		name->setString("bodyCount");
		return;
	}

	int bodyChannels = getChannelCountByBody();
	int jointChannels = getChannelCountByJoint();

	int32_t bodyIndex = floor((index - 1) / bodyChannels);
	int32_t jointIndex = ((index - 1) % bodyChannels) / jointChannels;
	int32_t channelIndex = ((index - 1) % bodyChannels) % jointChannels;

	std::string channelName = "body" + std::to_string(getBodyIndex(_tempBodies[bodyIndex]->uid)) + "/" + getJointName(jointIndex) + "/" + getJointChannelName(channelIndex);

	 name->setString(channelName.c_str());
}

void
Core::execute(CHOP_Output* output, const OP_Inputs* inputs, void* reserved)
{
	// First, set the body count
	output->channels[0][0] = _tempBodies.size();

	unsigned int currChannel = 1;

	for(pb::Body * body: _tempBodies) {
		for(pb::Joint &joint: body->skeleton()->joints) {
			bool posConf = joint.positionConfidence > 0 && joint.positionConfidence <= 1.0;
			bool orConf = joint.orientationConfidence > 0 && joint.orientationConfidence <= 1.0;

			if(_outputPositions) {
				output->channels[currChannel + 0][0] = posConf ? joint.position.x : 0;
				output->channels[currChannel + 1][0] = posConf ? joint.position.y : 0;
				output->channels[currChannel + 2][0] = posConf ? -joint.position.z : 0;
				currChannel += 3;
			}

			if(_outputOrientations) {
				output->channels[currChannel + 0][0] = orConf ? joint.orientation.x : 0;
				output->channels[currChannel + 1][0] = orConf ? joint.orientation.y : 0;
				output->channels[currChannel + 2][0] = orConf ? joint.orientation.z : 0;
				currChannel += 3;
			}

			if(_outputConfidences) {
				output->channels[currChannel + 0][0] = joint.positionConfidence;
				output->channels[currChannel + 1][0] = joint.orientationConfidence;
				currChannel += 2;
			}
		}
	}

	_indexMutex.unlock();
}

void
Core::setupParameters(OP_ParameterManager* manager, void *reserved1)
{
	OP_ParAppendResult res;

	// IP Field
//	OP_StringParameter ipField;
//	ipField.name = "Pbmasterip";
//	ipField.label = "PB Master IP";
//	ipField.defaultValue = "127.0.0.1";
//
//	res = manager->appendString(ipField);
//	assert(res == OP_ParAppendResult::Success);
//
//	// Port Field
//	OP_NumericParameter portField;
//	portField.name = "Pbmasterport";
//	portField.label = "PB Master port";
//	portField.defaultValues[0] = 40020;
//
//	res = manager->appendInt(portField);
//	assert(res == OP_ParAppendResult::Success);

	// Reconnect Button
	OP_NumericParameter reconnectPulse;
	reconnectPulse.name = "Pbreconnect";
	reconnectPulse.label = "Reconnect";

	res = manager->appendPulse(reconnectPulse);
	assert(res == OP_ParAppendResult::Success);

	// Output Selectors
	OP_NumericParameter positionsToggle;
	positionsToggle.name = "Pboutputpositions";
	positionsToggle.label = "Positions";
	positionsToggle.defaultValues[0] = 1;

	res = manager->appendToggle(positionsToggle);
	assert(res == OP_ParAppendResult::Success);

	OP_NumericParameter orientationsToggle;
	orientationsToggle.name = "Pboutputorientations";
	orientationsToggle.label = "Orientations";

	res = manager->appendToggle(orientationsToggle);
	assert(res == OP_ParAppendResult::Success);

	OP_NumericParameter confsToggle;
	confsToggle.name = "Pboutputconfs";
	confsToggle.label = "Confidences";

	res = manager->appendToggle(confsToggle);
	assert(res == OP_ParAppendResult::Success);

	// Body index reset
	OP_NumericParameter resetIndex;
	resetIndex.name = "Pbresetindexes";
	resetIndex.label = "Reset indexes";

	res = manager->appendPulse(resetIndex);
	assert(res == OP_ParAppendResult::Success);
}

void 
Core::pulsePressed(const char* name, void* reserved1)
{
	// Reconnect button
	if(std::string(name) == "Pbreconnect") {
		_socketMutex.lock();
		if(_socket != nullptr) {
			_socket->close();
		}
		_socketMutex.unlock();
		return;
	}

	// Reset ids button
	if(std::string(name) == "Pbresetindexes") {
		_indexMutex.lock();
		_bodiesIndex.clear();
		_indexMutex.unlock();
		return;
	}
}

void Core::getWarningString(OP_String * warning, void *reserved1) {
	if(_socket != nullptr && _socket->getStatus() == pb::network::SocketStatus::ready)
		return;

	warning->setString("Not connected to a pb-master");
}

// MARK: - SocketDelegate

void Core::socketDidOpen(pb::network::Socket * socket) {}

void Core::socketDidReceive(pb::network::Socket * socket, pb::network::messages::Datagram * datagram) {

	// Validate the datagram type
	if(datagram->type() != pb::network::messages::Datagram_Type_TRACKED_BODIES) {
		return; // This datatgram is not for us
	}

	// Unpack the datagram
	pb::network::messages::TrackedBodies trackedBodies;
	datagram->data().UnpackTo(&trackedBodies);

	// Fill in the buffer with the received bodies
	_bodiesBufferMutex.lock();

	int bodiesCount = trackedBodies.bodies_size();

	// For each received body
	for(int i = 0; i < bodiesCount; ++i) {
		pb::Body * body = new pb::Body(trackedBodies.bodies(i));

		// Is there already a body with the same uid in the buffer ?
		if(_bodiesBuffer.find(body->uid) != _bodiesBuffer.end()) {
			// A body is already stored, free it
			delete _bodiesBuffer[body->uid];
		}

		// Store the body
		_bodiesBuffer[body->uid] = body;
	}

	_bodiesBufferMutex.unlock();

	delete datagram;
}

void Core::socketDidClose(pb::network::Socket * socket) {
	// Empty the buffers
	_bodiesBufferMutex.lock();

	for(std::pair<pb::bodyUID, pb::Body *> pair: _bodiesBuffer) {
		delete pair.second;
	}

	_bodiesBuffer.clear();
	clearTempBodies();

	_bodiesBufferMutex.unlock();
}


// MARK: - Internal

void Core::clearTempBodies() {
	for(pb::Body * body: _tempBodies) {
		delete body;
	}
	_tempBodies.clear();
}

int Core::getChannelCountByBody() {
	return getChannelCountByJoint() * 15;
}

int Core::getChannelCountByJoint() {
	unsigned short int count = 0;

	if(_outputPositions)
		count += 3;

	if(_outputOrientations)
		count += 3;

	if(_outputConfidences)
		count += 2;

	return count;
}

unsigned long Core::getBodyIndex(const pb::bodyUID &bodyUID) {
	if(_bodiesIndex.find(bodyUID) != _bodiesIndex.end())
		return _bodiesIndex[bodyUID];

	_bodiesIndex[bodyUID] = _bodiesIndex.size();
	return _bodiesIndex[bodyUID];
}

std::string Core::getJointName(const int &jointIndex) {
	switch(jointIndex) {
		case  0: return "head";
		case  1: return "neck";
		case  2: return "leftShoulder";
		case  3: return "rightShoulder";
		case  4: return "leftElbow";
		case  5: return "rightElbow";
		case  6: return "leftHand";
		case  7: return "rightHand";
		case  8: return "torso";
		case  9: return "leftHip";
		case 10: return "rightHip";
		case 11: return "leftKnee";
		case 12: return "rightKnee";
		case 13: return "leftFoot";
		case 14: return "rightFoot";
		default: return std::to_string(jointIndex);
	}
}

std::string Core::getJointChannelName(const int &index) {

	int i = index;

	if(_outputPositions) {
		switch(i) {
			case  0: return "tx";
			case  1: return "ty";
			case  2: return "tz";
			default: i -= 3;
		}
	}

	if(_outputOrientations) {
		switch(i) {
			case  0: return "rx";
			case  1: return "ry";
			case  2: return "rz";
			case  4: return "rw";
			default: i -= 4;
		}
	}

	if(_outputConfidences) {
		switch(i) {
			case  0: return "tconf";
			case  1: return "rconf";
			default: i -= 2;
		}
	}

	return std::to_string(index);
}

