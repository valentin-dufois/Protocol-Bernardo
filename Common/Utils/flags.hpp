//
//  flags.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-10-12.
//

#ifndef flags_hpp
#define flags_hpp

#include <gflags/gflags.h>

DECLARE_int32(loglevel);
DECLARE_string(interface);
DECLARE_string(broadcastInterface);
DECLARE_bool(liveview);
DECLARE_string(layout);

#endif /* flags_hpp */
