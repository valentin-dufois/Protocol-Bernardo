//
//  thread.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-12.
//

#ifndef thread_h
#define thread_h

#include <thread>
#include <chrono>

#include "Log.hpp"

namespace pb {
namespace thread {

inline void setName(const std::string &threadName) {
#ifdef __APPLE__
	pthread_setname_np(threadName.c_str());
#else
	pthread_setname_np(pthread_self(), threadName.c_str());
#endif
}

inline void cadence(const std::chrono::duration<double, std::milli> &workTime, const double targetSpeed) {

//	LOG_DEBUG(std::to_string(workTime.count()) + "/" + std::to_string(1.0/targetSpeed));

	if(workTime.count() > (1.0/targetSpeed))
		return; // Last iteration took longer than one frame to complete, do not yield

	std::chrono::duration<double, std::milli> delta(1.0/targetSpeed - workTime.count());
//	LOG_DEBUG(std::to_string(delta.count()));

	// Temporary pause the thread
	std::this_thread::sleep_for(delta * 1000);
}

} /* ::thread */
} /* ::pb */

#endif /* thread_h */
