//
//  getBehaviour.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#include "Behaviour.hpp"
#include "../Core/Machine.hpp"

#include <iostream>

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

// TREE 5
#include "T-05/B-500/B-500.hpp"
#include "T-05/B-501/B-501.hpp"
#include "T-05/B-502/B-502.hpp"
#include "T-05/B-503/B-503.hpp"
#include "T-05/B-504/B-504.hpp"
#include "T-05/B-505/B-505.hpp"
#include "T-05/B-506/B-506.hpp"
#include "T-05/B-507/B-507.hpp"
#include "T-05/B-508/B-508.hpp"
#include "T-05/B-509/B-509.hpp"
#include "T-05/B-510/B-510.hpp"
#include "T-05/B-511/B-511.hpp"
#include "T-05/B-512/B-512.hpp"
#include "T-05/B-513/B-513.hpp"
#include "T-05/B-514/B-514.hpp"

// TREE 6
#include "T-06/B-600/B-600.hpp"
#include "T-06/B-601/B-601.hpp"
#include "T-06/B-602/B-602.hpp"
#include "T-06/B-603/B-603.hpp"
#include "T-06/B-604/B-604.hpp"
#include "T-06/B-605/B-605.hpp"
#include "T-06/B-606/B-606.hpp"
#include "T-06/B-607/B-607.hpp"
#include "T-06/B-608/B-608.hpp"
#include "T-06/B-609/B-609.hpp"
#include "T-06/B-610/B-610.hpp"
#include "T-06/B-611/B-611.hpp"
#include "T-06/B-612/B-612.hpp"
#include "T-06/B-613/B-613.hpp"

// TREE 7
#include "T-07/B-700/B-700.hpp"
#include "T-07/B-701/B-701.hpp"
#include "T-07/B-702/B-702.hpp"
#include "T-07/B-703/B-703.hpp"
#include "T-07/B-704/B-704.hpp"
#include "T-07/B-705/B-705.hpp"
#include "T-07/B-706/B-706.hpp"

// TREE 8
#include "T-08/B-800/B-800.hpp"
#include "T-08/B-801/B-801.hpp"
#include "T-08/B-802/B-802.hpp"
#include "T-08/B-803/B-803.hpp"
#include "T-08/B-804/B-804.hpp"
#include "T-08/B-805/B-805.hpp"
#include "T-08/B-806/B-806.hpp"
#include "T-08/B-807/B-807.hpp"
#include "T-08/B-808/B-808.hpp"
#include "T-08/B-809/B-809.hpp"
#include "T-08/B-810/B-810.hpp"
#include "T-08/B-811/B-811.hpp"
#include "T-08/B-812/B-812.hpp"
#include "T-08/B-813/B-813.hpp"
#include "T-08/B-814/B-814.hpp"
#include "T-08/B-815/B-815.hpp"
#include "T-08/B-816/B-816.hpp"
#include "T-08/B-817/B-817.hpp"
#include "T-08/B-818/B-818.hpp"
#include "T-08/B-819/B-819.hpp"
#include "T-08/B-820/B-820.hpp"
#include "T-08/B-821/B-821.hpp"
#include "T-08/B-822/B-822.hpp"
#include "T-08/B-823/B-823.hpp"
#include "T-08/B-824/B-824.hpp"
#include "T-08/B-825/B-825.hpp"

// TREE 9
#include "T-09/B-900/B-900.hpp"
#include "T-09/B-901/B-901.hpp"
#include "T-09/B-902/B-902.hpp"

// TREE 12
#include "T-12/B-1200/B-1200.hpp"
#include "T-12/B-1201/B-1201.hpp"
#include "T-12/B-1202/B-1202.hpp"


Behaviour * Behaviour::get(const talkers::BehaviourID behaviourID) {
	switch (behaviourID) {
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

		// MARK: - TREE 5
		case 500: return new B500();
		case 501: return new B501();
		case 502: return new B502();
		case 503: return new B503();
		case 504: return new B504();
		case 505: return new B505();
		case 506: return new B506();
		case 507: return new B507();
		case 508: return new B508();
		case 509: return new B509();
		case 510: return new B510();
		case 511: return new B511();
		case 512: return new B512();
		case 513: return new B513();
		case 514: return new B514();

		// MARK: - TREE 6
		case 600: return new B600();
		case 601: return new B601();
		case 602: return new B602();
		case 603: return new B603();
		case 604: return new B604();
		case 605: return new B605();
		case 606: return new B606();
		case 607: return new B607();
		case 608: return new B608();
		case 609: return new B609();
		case 610: return new B610();
		case 611: return new B611();
		case 612: return new B612();
		case 613: return new B613();

			// MARK: - TREE 7
		case 700: return new B700();
		case 701: return new B701();
		case 702: return new B702();
		case 703: return new B703();
		case 704: return new B704();
		case 705: return new B705();
		case 706: return new B706();

			// MARK: - TREE 8
		case 800: return new B800();
		case 801: return new B801();
		case 802: return new B802();
		case 803: return new B803();
		case 804: return new B804();
		case 805: return new B805();
		case 806: return new B806();
		case 807: return new B807();
		case 808: return new B808();
		case 809: return new B809();
		case 810: return new B810();
		case 811: return new B811();
		case 812: return new B812();
		case 813: return new B813();
		case 814: return new B814();
		case 815: return new B815();
		case 816: return new B816();
		case 817: return new B817();
		case 818: return new B818();
		case 819: return new B819();
		case 820: return new B820();
		case 821: return new B821();
		case 822: return new B822();
		case 823: return new B823();
		case 824: return new B824();
		case 825: return new B825();

			// MARK: - TREE 9
		case 900: return new B900();
		case 901: return new B901();
		case 902: return new B902();

			// MARK: - TREE 12
		case 1200: return new B1200();
		case 1201: return new B1201();
		case 1202: return new B1202();

		default:
			std::cout << "*** No behaviour " << behaviourID << std::endl;
			return nullptr;
	}
}

