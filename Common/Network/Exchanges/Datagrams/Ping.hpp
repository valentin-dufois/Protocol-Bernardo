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

class BaseSocket;

class Ping {
protected:
	void ping(BaseSocket * socket);

	void onPing(protobuf::Any * data, BaseSocket * socket);

	void onPong(protobuf::Any * data, BaseSocket * socket);
};

} /* ::network */
} /* ::pb */

#endif /* Ping_hpp */
