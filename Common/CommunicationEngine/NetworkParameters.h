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

// Discovery ports
#define ADVERTISER_PORT 40001
#define BROWSER_PORT ADVERTISER_PORT

// Communication ports
#define DEFAULT_SERVER_PORT 40010
#define ACQUISITOR_SERVER_PORT DEFAULT_SERVER_PORT
#define BROADCASTER_SERVER_PORT 40020
#define MASTER_SERVER_PORT DEFAULT_SERVER_PORT

#endif /* NetworkParameters_h */
