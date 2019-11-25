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

using NetworkPort = unsigned int;

// MARK: Discovery ports
const NetworkPort discoveryPortTracker = 40001;
const NetworkPort discoveryPortReceiver = 40002;
const NetworkPort discoveryPortMaster = 40003;

// MARK: Communication ports
const NetworkPort serverPortTracker = 40010;
const NetworkPort serverPortReceiver = 40020;
const NetworkPort serverPortMaster = 40030;

} /* ::network */
} /* ::pb */

#endif /* NetworkParameters_h */
