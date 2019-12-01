//
//  Ping.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-30.
//

#ifndef Ping_hpp
#define Ping_hpp

#include "../../Messages/messages.hpp"

namespace pb {
namespace network {

class Socket;

class Ping {
protected:
	void ping(Socket * socket);

	void onPing(protobuf::Any * data, Socket * socket);

	void onPong(protobuf::Any * data, Socket * socket);
};

} /* ::network */
} /* ::pb */

#endif /* Ping_hpp */
