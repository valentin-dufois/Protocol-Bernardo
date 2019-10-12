//
//  flags.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-10-12.
//

#include "flags.hpp"

/// loglevel
DEFINE_int32(loglevel, 1, "Set the log level.\n1 = All logs; 2 = Informatives logs; 3 = Warnings; 4 = Errors only; 5 = No logs");


#ifdef MACHINE_ACQUISITOR

/// liveview
DEFINE_bool(liveview, false, "Enable liveview from the connected devices. Liveview is useful for pl;acing captation devices but should not be used for live performances as it degrades the acquisitor performances.");

#endif /* MACHINE_ACQUISITOR */
