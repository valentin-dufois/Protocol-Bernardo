//
//  Message.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-27.
//

#ifndef Message_h
#define Message_h

#include "../Utils/StateValue.hpp"

struct Message {
	State values;

	unsigned int behaviour;

	std::string caption;
};

#endif /* Message_h */
