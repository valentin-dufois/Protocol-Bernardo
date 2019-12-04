//
//  Network.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-15.
//

#ifndef Network_h
#define Network_h

// This files import all headers declaring elemens in the pb::network
// namespace

// MARK: Core Network Functionnalities
#include "Network/Endpoint.hpp"
#include "Network/NetworkEngine.hpp"
#include "Network/NetworkParameters.h"
#include "Network/Server.hpp"

// MARK: Exchanges
#include "Network/Exchanges/Socket.hpp"
#include "Network/Exchanges/SocketDelegate.hpp"

// MARK: Discovery
#include "Network/Discovery/Advertiser.hpp"
#include "Network/Discovery/Browser.hpp"

// MARK: Messages
#include "Network/Messages/messages.hpp"

// MARK: PB Specifics
#include "Network/PB/PBReceiver.hpp"


#endif /* Network_h */
