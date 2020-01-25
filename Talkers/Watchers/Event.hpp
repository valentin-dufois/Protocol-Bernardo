//
//  Event.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-08.
//

#ifndef Event_h
#define Event_h

#include "../main.hpp"
#include <string>
#include <chrono>


struct Event {
	/// Name of the event
	std::string name;

	/// Time point when the event was detected
	std::chrono::system_clock::time_point time = std::chrono::system_clock::now();

	/// All the values attached to this behabiour, may be none
	State values;

	/// The ID of the behaviour this event is supposed to trigger
	talkers::BehaviourID behaviour;
};

#endif /* Event_h */
