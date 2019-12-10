//
//  Endpoint.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-11-15.
//

#include "Endpoint.hpp"

namespace pb {
namespace network {

Endpoint::Endpoint(const Type &aType):
type(aType) {}

Endpoint::Endpoint(const std::string &aIP, const unsigned int &aPort):
ip(aIP),
port(aPort) {}

Endpoint::Endpoint(const std::string &aIP,
				  const std::string &aName,
				  const Type &aType):
ip(aIP),
name(aName),
type(aType) {}

Endpoint::Endpoint(const messages::Endpoint message):
	name(std::string(message.name()))
{
	switch(message.type()) {
		case messages::Endpoint_Type_TRACKER:
			type = Type::tracker;
			break;
		case messages::Endpoint_Type_BROADCASTER:
			type = Type::receiver;
			break;
		case messages::Endpoint_Type_MASTER:
			type = Type::master;
			break;
		case messages::Endpoint_Type_TERMINAL:
			type = Type::terminal;
			break;
		default:
			type = Type::undefined;
	}
}

Endpoint::Endpoint(const messages::Endpoint message,
				  const boost::asio::ip::udp::endpoint &endpoint):
	Endpoint(message)
{
	ip = endpoint.address().to_string();
}

Endpoint::Endpoint(const boost::asio::ip::tcp::endpoint &endpoint) {
	ip = endpoint.address().to_string();
	port = endpoint.port();
}

} /* ::network */
} /* ::pb */
