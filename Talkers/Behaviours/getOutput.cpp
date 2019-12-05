
//
//  getOutput.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#include "Output.hpp"

#include <iostream>

// TREE 1
#include "B-100/S-100-00.hpp"
#include "B-100/S-100-01.hpp"
#include "B-101/S-101-00.hpp"
#include "B-102/S-102-00.hpp"
#include "B-103/S-103-00.hpp"
#include "B-104/S-104-00.hpp"
#include "B-105/S-105-00.hpp"
#include "B-106/S-106-00.hpp"
#include "B-107/S-107-00.hpp"
#include "B-108/S-108-00.hpp"
#include "B-109/S-109-00.hpp"
#include "B-110/S-110-00.hpp"
#include "B-111/S-111-00.hpp"
#include "B-112/S-112-00.hpp"
#include "B-113/S-113-00.hpp"

Output * Output::get(const talkers::OutputID id) {
	switch (id) {
		// MARK: - TREE 1
		case 10000: return new S10000();
		case 10001: return new S10001();
		case 10100: return new S10100();
		case 10200: return new S10200();
		case 10300: return new S10300();
		case 10400: return new S10400();
		case 10500: return new S10500();
		case 10600: return new S10600();
		case 10700: return new S10700();
		case 10800: return new S10800();
		case 10900: return new S10900();
		case 11000: return new S11000();
		case 11100: return new S11100();
		case 11200: return new S11200();
		case 11300: return new S11300();
		default:
			std::cout << "*** No output " << id << std::endl;
			return nullptr;
	}
}
