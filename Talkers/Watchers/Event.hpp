//
//  Event.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-08.
//

#ifndef Event_h
#define Event_h

#include "../main.hpp"
#include "../Utils/StateValue.hpp"
#include <string>
#include <chrono>

struct Event {
	std::string name;
	std::chrono::system_clock::time_point time = std::chrono::system_clock::now();
	State values;
	talkers::BehaviourID behaviour;
};

#endif /* Event_h */
