//
//  Ping.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-30.
//

#ifndef Ping_hpp
#define Ping_hpp

namespace google::protobuf {
	class Any;
}

namespace pb {
namespace network {

class Socket;

class Ping {
protected:
	void ping(Socket * socket);

	void onPing(google::protobuf::Any * data, Socket * socket);

	void onPong(google::protobuf::Any * data, Socket * socket);
};

} /* ::network */
} /* ::pb */

#endif /* Ping_hpp */
