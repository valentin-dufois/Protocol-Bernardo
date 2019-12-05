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
constexpr NetworkPort discoveryPortTracker = 42001;
constexpr NetworkPort discoveryPortReceiver = 42002;
constexpr NetworkPort discoveryPortTerminal = 42003;

// MARK: Server ports
constexpr NetworkPort serverPortTracker = 42010;
constexpr NetworkPort serverPortReceiver = 42020;
constexpr NetworkPort serverPortTerminal = 42030;

// MARK: Advertiser
constexpr unsigned short int advertiserRate = 1; // Advertise every X seconds


// MARK: - PB-related-but-not-used-directly ports
constexpr NetworkPort serverPortTalker = 42100;
constexpr NetworkPort discoveryPortTalker = 42101;

} /* ::network */
} /* ::pb */

#endif /* NetworkParameters_h */
