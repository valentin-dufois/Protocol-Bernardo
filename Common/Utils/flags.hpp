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


#ifdef MACHINE_ACQUISITOR

/// liveview
DECLARE_bool(liveview);

#endif /* MACHINE_ACQUISITOR */


#endif /* flags_hpp */
