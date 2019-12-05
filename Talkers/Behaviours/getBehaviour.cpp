//
//  getBehaviour.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#include "Behaviour.hpp"

#include <iostream>

#include "B-000/B-000.hpp"

// TREE 1
#include "B-100/B-100.hpp"
#include "B-101/B-101.hpp"
#include "B-102/B-102.hpp"
#include "B-103/B-103.hpp"
#include "B-104/B-104.hpp"
#include "B-105/B-105.hpp"
#include "B-106/B-106.hpp"
#include "B-107/B-107.hpp"
#include "B-108/B-108.hpp"
#include "B-109/B-109.hpp"
#include "B-110/B-110.hpp"
#include "B-111/B-111.hpp"
#include "B-112/B-112.hpp"
#include "B-113/B-113.hpp"

Behaviour * Behaviour::get(const talkers::BehaviourID behaviourID) {
	switch (behaviourID) {
		case   0: return new B000();

		// MARK: - TREE 1
		case 100: return new B100();
		case 101: return new B101();
		case 102: return new B102();
		case 103: return new B103();
		case 104: return new B104();
		case 105: return new B105();
		case 106: return new B106();
		case 107: return new B107();
		case 108: return new B108();
		case 109: return new B109();
		case 110: return new B110();
		case 111: return new B111();
		case 112: return new B112();
		case 113: return new B113();
		default:
			std::cout << "*** No behaviour " << behaviourID << std::endl;
			return nullptr;
	}
}

