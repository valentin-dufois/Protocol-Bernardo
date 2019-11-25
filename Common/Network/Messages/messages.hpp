//
//  messages.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-20.
//

#ifndef messages_h
#define messages_h

#include "cpp/body.pb.h"

#include "cpp/layout.pb.h"

#include "cpp/maths.pb.h"

#include "cpp/network.pb.h"

/// Convenient namespace alias
namespace protobuf = google::protobuf;

namespace pb {
namespace network {

/// Convenient datagram builder
/// @param type The type of the datagram to build
/// @param data The data to put in the datagram
inline messages::Datagram * makeDatagram(const messages::Datagram_Type &type, const protobuf::Message &data) {
	protobuf::Any * anyMessage = new protobuf::Any();
	anyMessage->PackFrom(data);

	messages::Datagram * datagram = new messages::Datagram();
	datagram->set_type(type);
	datagram->set_allocated_data(anyMessage);

	return datagram;
}

/// Convenient datagram builder
inline messages::Datagram * makeDatagram(const messages::Datagram_Type &type) {
	messages::Datagram * datagram = new messages::Datagram();
	datagram->set_type(type);

	return datagram;
}

} /* network */
} /* pb */

#endif /* messages_h */
