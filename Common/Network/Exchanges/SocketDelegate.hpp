//
//  SocketDelegate.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-11-15.
//

#ifndef SocketDelegate_h
#define SocketDelegate_h

#include "../Messages/messages.hpp"

namespace pb {
namespace network {

class Socket;

class SocketDelegate {
public:
	/// Called when the socket did connect to its remote
	virtual void socketDidOpen(Socket *) {}

	/// Called everytime the socket received a datagram from the
	/// network. Some datagram with Socket-specific types, such as
	/// 'close' might not be propagated to this method.
	virtual void socketDidReceive(Socket *, messages::Datagram *) {}

	/// Called when the socket disconnects/closes
	///
	/// Once the socket is closed, a new one should be used to
	/// re-open the connection if needed
	///
	/// Calling the destructor on the socket will not trigger this
	/// callback
	virtual void socketDidClose(Socket *) {}
};

} /* ::network */
} /* ::pb */

#endif /* SocketDelegate_h */
