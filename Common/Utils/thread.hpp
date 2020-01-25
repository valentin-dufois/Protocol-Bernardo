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

/// Sets the name of the current thread
///
/// @param threadName new name for the tread
inline void setName(const std::string &threadName) {
#ifdef __APPLE__
	pthread_setname_np(threadName.c_str());
#elif !defined(_WIN32)
	pthread_setname_np(pthread_self(), threadName.c_str());
#endif
}

/// Pause the current thread to match the given frequency per seconds. If the given worktime is greater than the targeted frequency, nothing happens.
///
/// @param workTime How long the last operation took place
/// @param targetSpeed Frequency we are trying to reach
inline void cadence(const std::chrono::duration<double, std::milli> &workTime, const double targetSpeed) {
	const double frequency = 1000 / targetSpeed;

	if(workTime.count() > frequency)
		return; // Last iteration took longer than one frame to complete, do not yield

	std::chrono::duration<double, std::milli> delta(frequency - workTime.count());

	// Temporary pause the thread
	std::this_thread::sleep_for(delta);
}

} /* ::thread */
} /* ::pb */

#endif /* thread_h */
