
//
//  getOutput.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#include "Output.hpp"

#include <iostream>

// TREE 1
#include "T-01/B-100/S-100-00.hpp"
#include "T-01/B-100/S-100-01.hpp"
#include "T-01/B-101/S-101-00.hpp"
#include "T-01/B-102/S-102-00.hpp"
#include "T-01/B-103/S-103-00.hpp"
#include "T-01/B-104/S-104-00.hpp"
#include "T-01/B-105/S-105-00.hpp"
#include "T-01/B-106/S-106-00.hpp"
#include "T-01/B-107/S-107-00.hpp"
#include "T-01/B-108/S-108-00.hpp"
#include "T-01/B-109/S-109-00.hpp"
#include "T-01/B-110/S-110-00.hpp"
#include "T-01/B-111/S-111-00.hpp"
#include "T-01/B-112/S-112-00.hpp"
#include "T-01/B-113/S-113-00.hpp"

// TREE 2
#include "T-02/B-200/S-200-00.hpp"
#include "T-02/B-200/S-200-01.hpp"
#include "T-02/B-200/S-200-02.hpp"
#include "T-02/B-201/S-201-00.hpp"
#include "T-02/B-201/S-201-01.hpp"
#include "T-02/B-202/S-202-00.hpp"
#include "T-02/B-203/S-203-00.hpp"
#include "T-02/B-204/S-204-00.hpp"
#include "T-02/B-205/S-205-00.hpp"
#include "T-02/B-206/S-206-00.hpp"
#include "T-02/B-207/S-207-00.hpp"
#include "T-02/B-208/S-208-00.hpp"
#include "T-02/B-209/S-209-00.hpp"
#include "T-02/B-210/S-210-00.hpp"
#include "T-02/B-211/S-211-00.hpp"
#include "T-02/B-212/S-212-00.hpp"
#include "T-02/B-213/S-213-00.hpp"
#include "T-02/B-214/S-214-00.hpp"
#include "T-02/B-215/S-215-00.hpp"
#include "T-02/B-216/S-216-00.hpp"
#include "T-02/B-217/S-217-00.hpp"
#include "T-02/B-218/S-218-00.hpp"
#include "T-02/B-219/S-219-00.hpp"
#include "T-02/B-220/S-220-00.hpp"
#include "T-02/B-221/S-221-00.hpp"

// TREE 3
#include "T-03/B-300/S-300-00.hpp"
#include "T-03/B-301/S-301-00.hpp"
#include "T-03/B-302/S-302-00.hpp"
#include "T-03/B-303/S-303-00.hpp"
#include "T-03/B-304/S-304-00.hpp"
#include "T-03/B-304/S-304-01.hpp"
#include "T-03/B-305/S-305-00.hpp"
#include "T-03/B-306/S-306-00.hpp"
#include "T-03/B-307/S-307-00.hpp"
#include "T-03/B-307/S-307-01.hpp"
#include "T-03/B-308/S-308-00.hpp"
#include "T-03/B-309/S-309-00.hpp"
#include "T-03/B-310/S-310-00.hpp"
#include "T-03/B-311/S-311-00.hpp"
#include "T-03/B-312/S-312-00.hpp"
#include "T-03/B-313/S-313-00.hpp"
#include "T-03/B-314/S-314-00.hpp"
#include "T-03/B-315/S-315-00.hpp"
#include "T-03/B-316/S-316-00.hpp"
#include "T-03/B-317/S-317-00.hpp"
#include "T-03/B-318/S-318-00.hpp"
#include "T-03/B-319/S-319-00.hpp"

// TREE 4
#include "T-04/B-400/S-400-00.hpp"
#include "T-04/B-401/S-401-00.hpp"
#include "T-04/B-402/S-402-00.hpp"
#include "T-04/B-403/S-403-00.hpp"
#include "T-04/B-404/S-404-00.hpp"
#include "T-04/B-405/S-405-00.hpp"
#include "T-04/B-406/S-406-00.hpp"

// TREE 5
#include "T-05/B-500/S-500-00.hpp"
#include "T-05/B-501/S-501-00.hpp"
#include "T-05/B-502/S-502-00.hpp"
#include "T-05/B-503/S-503-00.hpp"
#include "T-05/B-504/S-504-00.hpp"
#include "T-05/B-505/S-505-00.hpp"
#include "T-05/B-506/S-506-00.hpp"
#include "T-05/B-507/S-507-00.hpp"
#include "T-05/B-508/S-508-00.hpp"
#include "T-05/B-509/S-509-00.hpp"
#include "T-05/B-510/S-510-00.hpp"
#include "T-05/B-511/S-511-00.hpp"
#include "T-05/B-512/S-512-00.hpp"
#include "T-05/B-513/S-513-00.hpp"
#include "T-05/B-514/S-514-00.hpp"

// TREE 6
#include "T-06/B-600/S-600-00.hpp"
#include "T-06/B-601/S-601-00.hpp"
#include "T-06/B-601/S-601-01.hpp"
#include "T-06/B-602/S-602-00.hpp"
#include "T-06/B-603/S-603-00.hpp"
#include "T-06/B-604/S-604-00.hpp"
#include "T-06/B-605/S-605-00.hpp"
#include "T-06/B-606/S-606-00.hpp"
#include "T-06/B-607/S-607-00.hpp"
#include "T-06/B-608/S-608-00.hpp"
#include "T-06/B-609/S-609-00.hpp"
#include "T-06/B-610/S-610-00.hpp"
#include "T-06/B-611/S-611-00.hpp"
#include "T-06/B-612/S-612-00.hpp"
#include "T-06/B-613/S-613-00.hpp"

// TREE 7
#include "T-07/B-700/S-700-00.hpp"
#include "T-07/B-701/S-701-00.hpp"
#include "T-07/B-702/S-702-00.hpp"
#include "T-07/B-703/S-703-00.hpp"
#include "T-07/B-704/S-704-00.hpp"
#include "T-07/B-704/S-704-01.hpp"
#include "T-07/B-705/S-705-00.hpp"
#include "T-07/B-706/S-706-00.hpp"

// TREE 8
#include "T-08/B-800/S-800-00.hpp"
#include "T-08/B-801/S-801-00.hpp"
#include "T-08/B-802/S-802-00.hpp"
#include "T-08/B-803/S-803-00.hpp"
#include "T-08/B-804/S-804-00.hpp"
#include "T-08/B-805/S-805-00.hpp"
#include "T-08/B-806/S-806-00.hpp"
#include "T-08/B-807/S-807-00.hpp"
#include "T-08/B-808/S-808-00.hpp"
#include "T-08/B-809/S-809-00.hpp"
#include "T-08/B-810/S-810-00.hpp"
#include "T-08/B-811/S-811-00.hpp"
#include "T-08/B-812/S-812-00.hpp"
#include "T-08/B-813/S-813-00.hpp"
#include "T-08/B-814/S-814-00.hpp"
#include "T-08/B-814/S-814-01.hpp"
#include "T-08/B-815/S-815-00.hpp"
#include "T-08/B-816/S-816-00.hpp"
#include "T-08/B-817/S-817-00.hpp"
#include "T-08/B-818/S-818-00.hpp"
#include "T-08/B-819/S-819-00.hpp"
#include "T-08/B-820/S-820-00.hpp"
#include "T-08/B-821/S-821-00.hpp"
#include "T-08/B-822/S-822-00.hpp"

#include "T-08/B-823/S-823-00.hpp"
#include "T-08/B-824/S-824-00.hpp"
#include "T-08/B-825/S-825-00.hpp"

// TREE 9
#include "T-09/B-900/S-900-00.hpp"
#include "T-09/B-901/S-901-00.hpp"
#include "T-09/B-902/S-902-00.hpp"

// TREE 12
#include "T-12/B-1200/S-1200-00.hpp"
#include "T-12/B-1201/S-1201-00.hpp"
#include "T-12/B-1202/S-1202-00.hpp"


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

		// MARK: - TREE 2
		case 20000: return new S20000();
		case 20001: return new S20001();
		case 20002: return new S20002();
		case 20100: return new S20100();
		case 20101: return new S20101();
		case 20200: return new S20200();
		case 20300: return new S20300();
		case 20400: return new S20400();
		case 20500: return new S20500();
		case 20600: return new S20600();
		case 20700: return new S20700();
		case 20800: return new S20800();
		case 20900: return new S20900();
		case 21000: return new S21000();
		case 21100: return new S21100();
		case 21200: return new S21200();
		case 21300: return new S21300();
		case 21400: return new S21400();
		case 21500: return new S21500();
		case 21600: return new S21600();
		case 21700: return new S21700();
		case 21800: return new S21800();
		case 21900: return new S21900();
		case 22000: return new S22000();
		case 22100: return new S22100();

			// MARK: - TREE 2
		case 30000: return new S30000();
		case 30100: return new S30100();
		case 30200: return new S30200();
		case 30300: return new S30300();
		case 30400: return new S30400();
		case 30401: return new S30401();
		case 30500: return new S30500();
		case 30600: return new S30600();
		case 30700: return new S30700();
		case 30701: return new S30701();
		case 30800: return new S30800();
		case 30900: return new S30900();
		case 31000: return new S31000();
		case 31100: return new S31100();
		case 31200: return new S31200();
		case 31300: return new S31300();
		case 31400: return new S31400();
		case 31500: return new S31500();
		case 31600: return new S31600();
		case 31700: return new S31700();
		case 31800: return new S31800();
		case 31900: return new S31900();

		// MARK: - TREE 4
		case 40000: return new S40000();
		case 40100: return new S40100();
		case 40200: return new S40200();
		case 40300: return new S40300();
		case 40400: return new S40400();
		case 40500: return new S40500();
		case 40600: return new S40600();

			// MARK: - TREE 5
		case 50000: return new S50000();
		case 50100: return new S50100();
		case 50200: return new S50200();
		case 50300: return new S50300();
		case 50400: return new S50400();
		case 50500: return new S50500();
		case 50600: return new S50600();
		case 50700: return new S50700();
		case 50800: return new S50800();
		case 50900: return new S50900();
		case 51000: return new S51000();
		case 51100: return new S51100();
		case 51200: return new S51200();
		case 51300: return new S51300();
		case 51400: return new S51400();

			// MARK: - TREE 6
		case 60000: return new S60000();
		case 60100: return new S60100();
		case 60101: return new S60101();
		case 60200: return new S60200();
		case 60300: return new S60300();
		case 60400: return new S60400();
		case 60500: return new S60500();
		case 60600: return new S60600();
		case 60700: return new S60700();
		case 60800: return new S60800();
		case 60900: return new S60900();
		case 61000: return new S61000();
		case 61100: return new S61100();
		case 61200: return new S61200();
		case 61300: return new S61300();

			// MARK: - TREE 7
		case 70000: return new S70000();
		case 70100: return new S70100();
		case 70200: return new S70200();
		case 70300: return new S70300();
		case 70400: return new S70400();
		case 70401: return new S70401();
		case 70500: return new S70500();
		case 70600: return new S70600();

			// MARK: - TREE 8
		case 80000: return new S80000();
		case 80100: return new S80100();
		case 80200: return new S80200();
		case 80300: return new S80300();
		case 80400: return new S80400();
		case 80500: return new S80500();
		case 80600: return new S80600();
		case 80700: return new S80700();
		case 80800: return new S80800();
		case 80900: return new S80900();
		case 81000: return new S81000();
		case 81100: return new S81100();
		case 81200: return new S81200();
		case 81300: return new S81300();
		case 81400: return new S81400();
		case 81401: return new S81401();
		case 81500: return new S81500();
		case 81600: return new S81600();
		case 81700: return new S81700();
		case 81800: return new S81800();
		case 81900: return new S81900();
		case 82000: return new S82000();
		case 82100: return new S82100();
		case 82200: return new S82200();
		case 82300: return new S82300();
		case 82400: return new S82400();
		case 82500: return new S82500();

			// MARK: - TREE 9
		case 90000: return new S90000();
		case 90100: return new S90100();
		case 90200: return new S90200();

			// MARK: - TREE 12
		case 120000: return new S120000();
		case 120100: return new S120100();
		case 120200: return new S120200();

		default:
			std::cout << "*** No output " << id << std::endl;
			return nullptr;
	}
}
