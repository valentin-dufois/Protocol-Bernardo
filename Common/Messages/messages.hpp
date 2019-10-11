//
//  messages.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-20.
//

#ifndef messages_h
#define messages_h

#include <grpc++/grpc++.h>

// #include "messages/body.grpc.pb.h"
#include "body.pb.h"

// #include "messages/layout.grpc.pb.h"
#include "layout.pb.h"

// #include "messages/maths.grpc.pb.h"
#include "maths.pb.h"

// #include "messages/network.grpc.pb.h"
#include "network.pb.h"

// #include "messages/services.grpc.pb.h"
#include "services.pb.h"

// Convenient namespace alias
namespace protobuf = google::protobuf;

#endif /* messages_h */
