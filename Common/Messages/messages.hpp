//
//  messages.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-20.
//

#ifndef messages_h
#define messages_h

#include "body.pb.h"

#include "layout.pb.h"

#include "maths.pb.h"

#include "network.pb.h"

/// Convenient namespace alias
namespace protobuf = google::protobuf;

namespace messages {

/// Convenient datagram builder
inline protobuf::Message * makeDatagram(const Datagram_Type &type, const protobuf::Message &data) {
	protobuf::Any * anyMessage = new protobuf::Any();
	anyMessage->PackFrom(data);

	Datagram * datagram = new Datagram();
	datagram->set_type(type);
	datagram->set_allocated_data(anyMessage);

	return datagram;
}

/// Convenient datagram builder
inline protobuf::Message * makeDatagram(const Datagram_Type &type) {
	Datagram * datagram = new Datagram();
	datagram->set_type(type);

	return datagram;
}

}

#endif /* messages_h */
