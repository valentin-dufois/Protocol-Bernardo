//
//  Ping.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-30.
//

#ifndef Ping_hpp
#define Ping_hpp

class Socket;
namespace google::protobuf {
	class Any;
}

class Ping {
protected:
	void ping(Socket * socket);

	void onPing(google::protobuf::Any * data, Socket * socket);

	void onPong(google::protobuf::Any * data, Socket * socket);
};

#endif /* Ping_hpp */
