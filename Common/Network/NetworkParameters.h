//
//  NetworkParameters.h
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-09-09.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef NetworkParameters_h
#define NetworkParameters_h

#include <string>

namespace pb {
namespace network {

using NetworkPort = unsigned short int;

// MARK: Discovery ports
constexpr NetworkPort discoveryPortTracker = 40001;
constexpr NetworkPort discoveryPortReceiver = 40002;
constexpr NetworkPort discoveryPortTerminal = 40003;

// MARK: Server ports
constexpr NetworkPort serverPortTracker = 40010;
constexpr NetworkPort serverPortReceiver = 40020;
constexpr NetworkPort serverPortTerminal = 40030;

// MARK: Advertiser
constexpr unsigned short int advertiserRate = 1; // Advertise every X seconds

} /* ::network */
} /* ::pb */

#endif /* NetworkParameters_h */
