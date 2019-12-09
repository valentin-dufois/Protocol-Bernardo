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
#include "T-01/B-100/B-100.hpp"
#include "T-01/B-101/B-101.hpp"
#include "T-01/B-102/B-102.hpp"
#include "T-01/B-103/B-103.hpp"
#include "T-01/B-104/B-104.hpp"
#include "T-01/B-105/B-105.hpp"
#include "T-01/B-106/B-106.hpp"
#include "T-01/B-107/B-107.hpp"
#include "T-01/B-108/B-108.hpp"
#include "T-01/B-109/B-109.hpp"
#include "T-01/B-110/B-110.hpp"
#include "T-01/B-111/B-111.hpp"
#include "T-01/B-112/B-112.hpp"
#include "T-01/B-113/B-113.hpp"

// TREE 2
#include "T-02/B-200/B-200.hpp"
#include "T-02/B-201/B-201.hpp"
#include "T-02/B-202/B-202.hpp"
#include "T-02/B-203/B-203.hpp"
#include "T-02/B-204/B-204.hpp"
#include "T-02/B-205/B-205.hpp"
#include "T-02/B-206/B-206.hpp"
#include "T-02/B-207/B-207.hpp"
#include "T-02/B-208/B-208.hpp"
#include "T-02/B-209/B-209.hpp"
#include "T-02/B-210/B-210.hpp"
#include "T-02/B-211/B-211.hpp"
#include "T-02/B-212/B-212.hpp"
#include "T-02/B-213/B-213.hpp"
#include "T-02/B-214/B-214.hpp"
#include "T-02/B-215/B-215.hpp"
#include "T-02/B-216/B-216.hpp"
#include "T-02/B-217/B-217.hpp"
#include "T-02/B-218/B-218.hpp"
#include "T-02/B-219/B-219.hpp"
#include "T-02/B-220/B-220.hpp"
#include "T-02/B-221/B-221.hpp"

// TREE 3
#include "T-03/B-300/B-300.hpp"
#include "T-03/B-301/B-301.hpp"
#include "T-03/B-302/B-302.hpp"
#include "T-03/B-303/B-303.hpp"
#include "T-03/B-304/B-304.hpp"
#include "T-03/B-305/B-305.hpp"
#include "T-03/B-306/B-306.hpp"
#include "T-03/B-307/B-307.hpp"
#include "T-03/B-308/B-308.hpp"
#include "T-03/B-309/B-309.hpp"
#include "T-03/B-310/B-310.hpp"
#include "T-03/B-311/B-311.hpp"
#include "T-03/B-312/B-312.hpp"
#include "T-03/B-313/B-313.hpp"
#include "T-03/B-314/B-314.hpp"
#include "T-03/B-315/B-315.hpp"
#include "T-03/B-316/B-316.hpp"
#include "T-03/B-317/B-317.hpp"
#include "T-03/B-318/B-318.hpp"
#include "T-03/B-319/B-319.hpp"

// TREE 4
#include "T-04/B-400/B-400.hpp"
#include "T-04/B-401/B-401.hpp"
#include "T-04/B-402/B-402.hpp"
#include "T-04/B-403/B-403.hpp"
#include "T-04/B-404/B-404.hpp"
#include "T-04/B-405/B-405.hpp"
#include "T-04/B-406/B-406.hpp"



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

		// MARK: - TREE 2
		case 200: return new B200();
		case 201: return new B201();
		case 202: return new B202();
		case 203: return new B203();
		case 204: return new B204();
		case 205: return new B205();
		case 206: return new B206();
		case 207: return new B207();
		case 208: return new B208();
		case 209: return new B209();
		case 210: return new B210();
		case 211: return new B211();
		case 212: return new B212();
		case 213: return new B213();
		case 214: return new B214();
		case 215: return new B215();
		case 216: return new B216();
		case 217: return new B217();
		case 218: return new B218();
		case 219: return new B219();
		case 220: return new B220();
		case 221: return new B221();

			// MARK: - TREE 2
		case 300: return new B300();
		case 301: return new B301();
		case 302: return new B302();
		case 303: return new B303();
		case 304: return new B304();
		case 305: return new B305();
		case 306: return new B306();
		case 307: return new B307();
		case 308: return new B308();
		case 309: return new B309();
		case 310: return new B310();
		case 311: return new B311();
		case 312: return new B312();
		case 313: return new B313();
		case 314: return new B314();
		case 315: return new B315();
		case 316: return new B316();
		case 317: return new B317();
		case 318: return new B318();
		case 319: return new B319();

		// MARK: - TREE 4
		case 400: return new B400();
		case 401: return new B401();
		case 402: return new B402();
		case 403: return new B403();
		case 404: return new B404();
		case 405: return new B405();
		case 406: return new B406();

		default:
			std::cout << "*** No behaviour " << behaviourID << std::endl;
			return nullptr;
	}
}

