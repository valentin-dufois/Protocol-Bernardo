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

class TerminalServer: public network::Server {
public:

	TerminalServer(): Server(serverPortTerminal, discoveryPortTerminal, Endpoint::terminal) {}

	/// Handle to the layout engine
	LayoutEngine * layoutEngine = nullptr;

	TrackingEngine * trackingEngine = nullptr;

protected:
	void socketDidOpen(Socket * newSocket) override;

	void socketDidClose(Socket * closedSocket) override;

private:

	void socketDidReceive(Socket * socket, messages::Datagram * datagram) override;

	void onStatusRequest(Socket * socket);

	// MARK: - Layout methods

	void onLayoutList(Socket * socket);

	void onLayoutCreate(protobuf::Any * data, Socket * socket);

	void onLayoutOpen(protobuf::Any * data, Socket * socket);

	void onLayoutClose(Socket * socket);

	void onLayoutRename(protobuf::Any * data, Socket * socket);

	void onLayoutUpdate(protobuf::Any * data, Socket * socket);

	void onLayoutDelete(protobuf::Any * data, Socket * socket);


	void onCalibrationSet(protobuf::Any * data);
};

} /* ::master */
} /* ::pb */

#endif /* MasterServer_hpp */
