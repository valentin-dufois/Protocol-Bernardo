//
//  getBehaviour.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#include "Behaviour.hpp"

#include <iostream>

#include "B-000/B-000.hpp"

#include "B-100/B-100.hpp"

Behaviour * Behaviour::get(unsigned int behaviourID) {
	switch (behaviourID) {
		case   0: return new B000();
		case 100: return new B100();
		default:
			std::cout << "No behaviour " << behaviourID;
			return nullptr;
	}
}
