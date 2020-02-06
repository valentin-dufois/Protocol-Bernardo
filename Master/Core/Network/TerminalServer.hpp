//
//  TerminalServer.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-10-02.
//

#ifndef MasterServer_hpp
#define MasterServer_hpp

#include "../../../Common/Network.hpp"

namespace pb {
namespace master {

using namespace pb::network;

class TrackingEngine;
class LayoutEngine;

class TerminalServer: public network::Server<> {
public:

	TerminalServer(): Server<messages::Datagram>(serverPortTerminal, discoveryPortTerminal, Endpoint::terminal) {}

	/// Handle to the layout engine
	LayoutEngine * layoutEngine = nullptr;

	TrackingEngine * trackingEngine = nullptr;

protected:
	void socketDidOpen(BaseSocket * newSocket) override;

	void socketDidClose(BaseSocket * closedSocket) override;

private:

	void socketDidReceive(BaseSocket * socket, protobuf::Message * datagram) override;

	void onStatusRequest(BaseSocket * socket);

	// MARK: - Layout methods

	void onLayoutList(BaseSocket * socket);

	void onLayoutCreate(protobuf::Any * data, BaseSocket * socket);

	void onLayoutOpen(protobuf::Any * data, BaseSocket * socket);

	void onLayoutClose(BaseSocket * socket);

	void onLayoutRename(protobuf::Any * data, BaseSocket * socket);

	void onLayoutUpdate(protobuf::Any * data, BaseSocket * socket);

	void onLayoutDelete(protobuf::Any * data, BaseSocket * socket);


	void onCalibrationSet(protobuf::Any * data);
};

} /* ::master */
} /* ::pb */

#endif /* MasterServer_hpp */
