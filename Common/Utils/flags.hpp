//
//  flags.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-10-12.
//

#ifndef flags_hpp
#define flags_hpp

#include <gflags/gflags.h>

/// loglevel
DECLARE_int32(loglevel);
DECLARE_string(interface);
DECLARE_string(broadcastInterface);


#ifdef MACHINE_ACQUISITOR

/// liveview
DECLARE_bool(liveview);

#endif /* MACHINE_ACQUISITOR */

//#ifdef MACHINE_MASTER

DECLARE_string(layout);

//#endif /* MACHINE_MASTER */

#endif /* flags_hpp */
