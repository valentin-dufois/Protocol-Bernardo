//
//  Core.hpp
//  pb-receiver-touch
//
//  Created by Valentin Dufois on 2019-11-19.
//

#include <map>
#include <set>
#include <mutex>

#include "CHOP_CPlusPlusBase.h"

#include "../Common/common.hpp"
#include "../Common/Network.hpp"

namespace pb {
struct Body;
}

/*

This example file implements a class that does 2 different things depending on
if a CHOP is connected to the CPlusPlus CHOPs input or not.
The example is timesliced, which is the more complex way of working.

If an input is connected the node will output the same number of channels as the
input and divide the first 'N' samples in the input channel by 2. 'N' being the current
timeslice size. This is noteworthy because if the input isn't changing then the output
will look wierd since depending on the timeslice size some number of the first samples
of the input will get used.

If no input is connected then the node will output a smooth sine wave at 120hz.
*/


// To get more help about these functions, look at CHOP_CPlusPlusBase.h
class Core : public CHOP_CPlusPlusBase, public pb::network::SocketDelegate
{
public:

	Core();

	virtual ~Core();

	// MARK: - TouchDesigner handles

	virtual void		getGeneralInfo(CHOP_GeneralInfo *,
								  const OP_Inputs *,
								  void * ) override;

	virtual bool		getOutputInfo(CHOP_OutputInfo *,
								 const OP_Inputs *,
								 void *) override;

	virtual void		getChannelName(int32_t 	 index,
								  OP_String * name,
								  const OP_Inputs *,
								  void * reserved) override;

	virtual void		execute(CHOP_Output *,
							const OP_Inputs *,
							void * reserved) override;

	virtual void		setupParameters(OP_ParameterManager * manager,
								   void * reserved1) override;

	virtual void		pulsePressed(const char * name,
								void * reserved1) override;

	virtual void
	getWarningString(OP_String *warning, void *reserved1) override;

	// MARK: - SocketDelegate

	virtual void socketDidOpen(pb::network::Socket * socket) override;

	virtual void socketDidReceive(pb::network::Socket * socket, pb::network::messages::Datagram * datagram) override;

	virtual void socketDidClose(pb::network::Socket * socket) override;

private:

	// MARK: - Internal

	/// Tell if we should output the positions channel
	bool _outputPositions = false;

	/// Tell if we should output the orientations channel
	bool _outputOrientations = false;

	/// Tell if we should output the confidences
	bool _outputConfidences = false;

	pb::network::Browser * _browser;

	/// The socket used to connect to the master
	pb::network::Socket * _socket = nullptr;

	/// The buffer holding bodies received from the network but not yet processed
	std::map<pb::bodyUID, pb::Body *> _bodiesBuffer;

	/// Holds the bodies for the current execution
	std::vector<pb::Body *> _tempBodies;

	/// Set the index of each bodies
	std::map<pb::bodyUID, unsigned long> _bodiesIndex;

	/// Clear the _tempBodies, freeing resources
	void clearTempBodies();

	/// Tells how many channel each Body requires for output base on the current users parameters
	int getChannelCountByBody();

	/// Tells how many channel each Joint requires for output base on the current users parameters
	int getChannelCountByJoint();

	/// Gives the corresponding body index for the given body UID. If tthe body isn't references, this method does it.
	unsigned long getBodyIndex(const pb::bodyUID &bodyUID);

	/// Gives the name of the specified joint based on its index
	std::string getJointName(const int &jointIndex);

	/// Gives the name of a channel based on its index in the joint and the current users parameters
	std::string getJointChannelName(const int &index);

	/// Mutex for `_bodiesBuffer`
	std::mutex _bodiesBufferMutex;

	/// Mutex for the socket
	std::mutex _socketMutex;

	/// Mutex for _bodiesIndex
	std::mutex _indexMutex;
};
