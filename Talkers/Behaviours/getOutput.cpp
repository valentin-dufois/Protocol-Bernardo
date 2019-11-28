
//
//  getOutput.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#include "Output.hpp"

#include <iostream>

Output * Output::get(const unsigned int id) {
	switch (id) {
		case 0:
			return nullptr;
		default:
			std::cout << "No output " << id << std::endl;
			return nullptr;
	}
}
