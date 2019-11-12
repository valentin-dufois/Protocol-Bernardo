//
//  flags.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-10-12.
//

#include "flags.hpp"

/// loglevel
DEFINE_int32(loglevel, 1, "Set the log level.\n1 = All logs; 2 = Informatives logs; 3 = Warnings; 4 = Errors only; 5 = No logs");
DEFINE_string(interface, "", "The network interface to use when advertising on the network. If left empty, the user may be prompted to choose the interface at run-time.");
DEFINE_string(broadcastInterface, "", "The network interface to use for broascsting the tracked bodies to display applications");

#ifdef MACHINE_ACQUISITOR

/// liveview
DEFINE_bool(liveview, false, "Enable liveview from the connected devices. Liveview is useful for placing captation devices but should not be used for live performances as it degrades the acquisitor performances.");

#endif /* MACHINE_ACQUISITOR */

//#ifdef MACHINE_MASTER

DEFINE_string(layout, "", "Specify which layout to use on application startup. Removes the need to set the active layout using a terminal");

//#endif /* MACHINE_MASTER */
