//
//  Behaviour.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-27.
//

#include "Behaviour.hpp"
#include "Message.hpp"
#include "Output.hpp"

bool Behaviour::importMessage(Message * message) {
	for(const std::string &valueName: _expectedInputs) {
		if(message->values.find(valueName) == message->values.end()) {
			return false;
		}

		_state[valueName] = message->values[valueName];
	}

	return true;
}

Output * Behaviour::getOutput() {
	for(talkers::OutputID outputID: _possibleOutputs) {
		Output * out = Output::get(outputID);

		if(out == nullptr)
			continue;

		if(out->isConditionValid(_state)) {
			return out;
		}

		delete out;
	}

	return nullptr;
}
