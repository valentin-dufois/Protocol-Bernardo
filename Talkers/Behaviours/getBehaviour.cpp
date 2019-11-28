//
//  getBehaviour.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#include "Behaviour.hpp"

#include <iostream>

#include "B-000/B-000.hpp"

Behaviour * Behaviour::get(unsigned int behaviourID) {
	switch (behaviourID) {
		case   0: return new B000();
		default:
			std::cout << "No behaviour " << behaviourID;
			return nullptr;
	}
}
