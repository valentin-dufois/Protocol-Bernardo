//
//  Endpoint.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-09-09.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef Endpoint_hpp
#define Endpoint_hpp

#include <string>
#include <boost/asio.hpp>

#include "../Utils/Log.hpp"

#include "../CommunicationEngine/NetworkParameters.h"
#include "messages.hpp"

/**
 An Endpoint represent a machine on the network
 */
struct Endpoint {
	/** The IP of the endpoint. For the current machine, this will always be `127.0.0.1` */
	std::string ip;

	/** The name of the machine, as defined by the network interface */
	std::string name;

	/** The role of the machine in the PB ecosysem */
	enum Type { undefined, acquisitor, broadcaster, master, terminal } type;

	// MARK: - Constructors

	/// Default constructor
	Endpoint() = default;

	/// Construct an endpoint using the given information
	Endpoint(const std::string &aIP, const std::string &aName, const Type &aType):
		ip(aIP),
		name(aName),
		type(aType) {};

	/// Construct an endpoint from the given message.
	/// There will not be any IP on this endpoint
	Endpoint(const messages::Endpoint message) {
		name = std::string(message.name());

		switch(message.type()) {
			case messages::Endpoint_Type_ACQUISITOR:
				type = Type::acquisitor;
				break;
			case messages::Endpoint_Type_BROADCASTER:
				type = Type::broadcaster;
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

	/// Construct an endpoint from the given message and using the given asio::endpoint for the IP.
	Endpoint(const messages::Endpoint message, const boost::asio::ip::udp::endpoint &endpoint) {
		ip = endpoint.address().to_string();
		name = std::string(message.name());

		switch(message.type()) {
			case messages::Endpoint_Type_ACQUISITOR:
				type = Type::acquisitor;
				break;
			case messages::Endpoint_Type_BROADCASTER:
				type = Type::broadcaster;
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

	Endpoint(const boost::asio::ip::tcp::endpoint &e) {
		ip = e.address().to_string();
	}

	// MARK: - Methods

	int getPort() const {
		switch (type) {
			case acquisitor: return ACQUISITOR_SERVER_PORT; break;
			case broadcaster: return BROADCASTER_SERVER_PORT; break;
			case master: return MASTER_SERVER_PORT; break;
			default:
				LOG_WARN("Building URI for non supported endpoint");
				return 0;
		}
	}

	std::string typeLabel() const {
		switch (type) {
			case Type::acquisitor: return "Acquisitor"; break;
			case Type::broadcaster: return "Broadcaster"; break;
			case Type::master: return "Master"; break;
			case Type::terminal: return "Terminal"; break;
			default: return "Unknown"; break;
		}
	}

	/// Gives the uri (ip + port) for the current endpoint. If the ip is missing, behaviour is undefined
	std::string uri() const {
		std::string port = std::to_string(getPort());

		if(port.empty())
			return ip; // No port, just return the ip

		return ip + ":" + port;
	}


	// MARK: - Operators

	/// Casts the endpoint to a message.
	/// - warning: the given message needs to be freed before being released
	operator messages::Endpoint * () const {
		messages::Endpoint * message = new messages::Endpoint;

		// Fill in the message
		message->set_name(name);

		switch (type) {
			case Type::acquisitor:
				message->set_type(messages::Endpoint_Type_ACQUISITOR); break;
			case Type::broadcaster:
				message->set_type(messages::Endpoint_Type_BROADCASTER); break;
			case Type::master:
				message->set_type(messages::Endpoint_Type_MASTER); break;
			case Type::terminal:
				message->set_type(messages::Endpoint_Type_TERMINAL); break;
			default:
				message->set_type(messages::Endpoint_Type_UNDEFINED); break;
		}

		return message;
	}

	/// Casts the endpoint as a TCP endpoint
	operator boost::asio::ip::tcp::endpoint () const {
		return boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip), getPort());
	}


	/// Tell if two endpoints are the same machine
	bool operator == (const Endpoint &b) const {
		return b.name == name && b.ip == ip && b.type == type;
	}

	/// Tell if two endoints are not the same machine
	bool operator != (const Endpoint &b) const {
		return !(*this == b);
	}
};

#endif /* Endpoint_hpp */
