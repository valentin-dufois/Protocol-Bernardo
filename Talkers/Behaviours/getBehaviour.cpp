//
//  getBehaviour.cpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#include "Behaviour.hpp"
#include "../Core/Machine.hpp"
#include "../../Common/Utils/Log.hpp"

#include <iostream>

// TREE 1
#include "T-1/B-1/B-1.hpp"
#include "T-1/B-3/B-3.hpp"
#include "T-1/B-4/B-4.hpp"
#include "T-1/B-5/B-5.hpp"
#include "T-1/B-6/B-6.hpp"
#include "T-1/B-7/B-7.hpp"
#include "T-1/B-8/B-8.hpp"
#include "T-1/B-9/B-9.hpp"
#include "T-1/B-10/B-10.hpp"
#include "T-1/B-12/B-12.hpp"
#include "T-1/B-13/B-13.hpp"
#include "T-1/B-14/B-14.hpp"
#include "T-1/B-15/B-15.hpp"
#include "T-1/B-16/B-16.hpp"

// TREE 2
#include "T-2/B-11/B-11.hpp"
#include "T-2/B-17/B-17.hpp"
#include "T-2/B-20/B-20.hpp"
#include "T-2/B-21/B-21.hpp"

// TREE 3
#include "T-3/B-18/B-18.hpp"
#include "T-3/B-23/B-23.hpp"
#include "T-3/B-48/B-48.hpp"
#include "T-3/B-49/B-49.hpp"
#include "T-3/B-55/B-55.hpp"
#include "T-3/B-59/B-59.hpp"
#include "T-3/B-61/B-61.hpp"
#include "T-3/B-62/B-62.hpp"
#include "T-3/B-63/B-63.hpp"
#include "T-3/B-64/B-64.hpp"
#include "T-3/B-65/B-65.hpp"
#include "T-3/B-67/B-67.hpp"
#include "T-3/B-68/B-68.hpp"
#include "T-3/B-69/B-69.hpp"
#include "T-3/B-71/B-71.hpp"
#include "T-3/B-72/B-72.hpp"
#include "T-3/B-73/B-73.hpp"
#include "T-3/B-75/B-75.hpp"
#include "T-3/B-76/B-76.hpp"
#include "T-3/B-77/B-77.hpp"
#include "T-3/B-78/B-78.hpp"
#include "T-3/B-80/B-80.hpp"
#include "T-3/B-82/B-82.hpp"
#include "T-3/B-85/B-85.hpp"
#include "T-3/B-86/B-86.hpp"
#include "T-3/B-88/B-88.hpp"
#include "T-3/B-89/B-89.hpp"

// TREE 4
#include "T-4/B-22/B-22.hpp"
#include "T-4/B-47/B-47.hpp"

// TREE 5
#include "T-5/B-50/B-50.hpp"
#include "T-5/B-52/B-52.hpp"
#include "T-5/B-53/B-53.hpp"
#include "T-5/B-54/B-54.hpp"
#include "T-5/B-56/B-56.hpp"
#include "T-5/B-57/B-57.hpp"
#include "T-5/B-58/B-58.hpp"
#include "T-5/B-60/B-60.hpp"
#include "T-5/B-70/B-70.hpp"
#include "T-5/B-81/B-81.hpp"
#include "T-5/B-83/B-83.hpp"
#include "T-5/B-84/B-84.hpp"
#include "T-5/B-87/B-87.hpp"
#include "T-5/B-90/B-90.hpp"
#include "T-5/B-91/B-91.hpp"
#include "T-5/B-92/B-92.hpp"
#include "T-5/B-93/B-93.hpp"
#include "T-5/B-94/B-94.hpp"
#include "T-5/B-95/B-95.hpp"
#include "T-5/B-96/B-96.hpp"
#include "T-5/B-97/B-97.hpp"
#include "T-5/B-98/B-98.hpp"

// TREE 6
#include "T-6/B-99/B-99.hpp"
#include "T-6/B-100/B-100.hpp"
#include "T-6/B-101/B-101.hpp"
#include "T-6/B-102/B-102.hpp"
#include "T-6/B-103/B-103.hpp"
#include "T-6/B-104/B-104.hpp"
#include "T-6/B-105/B-105.hpp"
#include "T-6/B-106/B-106.hpp"
#include "T-6/B-107/B-107.hpp"
#include "T-6/B-108/B-108.hpp"
#include "T-6/B-109/B-109.hpp"
#include "T-6/B-110/B-110.hpp"
#include "T-6/B-111/B-111.hpp"
#include "T-6/B-112/B-112.hpp"
#include "T-6/B-113/B-113.hpp"
#include "T-6/B-114/B-114.hpp"
#include "T-6/B-115/B-115.hpp"
#include "T-6/B-116/B-116.hpp"
#include "T-6/B-117/B-117.hpp"
#include "T-6/B-118/B-118.hpp"
#include "T-6/B-119/B-119.hpp"
#include "T-6/B-120/B-120.hpp"
#include "T-6/B-121/B-121.hpp"
#include "T-6/B-122/B-122.hpp"
#include "T-6/B-123/B-123.hpp"
#include "T-6/B-124/B-124.hpp"
#include "T-6/B-125/B-125.hpp"
#include "T-6/B-126/B-126.hpp"
#include "T-6/B-127/B-127.hpp"

// TREE 7
#include "T-7/B-128/B-128.hpp"
#include "T-7/B-129/B-129.hpp"
#include "T-7/B-130/B-130.hpp"
#include "T-7/B-131/B-131.hpp"
#include "T-7/B-132/B-132.hpp"
#include "T-7/B-133/B-133.hpp"
#include "T-7/B-135/B-135.hpp"

// TREE 9
#include "T-9/B-139/B-139.hpp"
#include "T-9/B-141/B-141.hpp"
#include "T-9/B-142/B-142.hpp"
#include "T-9/B-144/B-144.hpp"
#include "T-9/B-145/B-145.hpp"
#include "T-9/B-146/B-146.hpp"
#include "T-9/B-147/B-147.hpp"
#include "T-9/B-148/B-148.hpp"
#include "T-9/B-149/B-149.hpp"
#include "T-9/B-151/B-151.hpp"
#include "T-9/B-152/B-152.hpp"
#include "T-9/B-153/B-153.hpp"
#include "T-9/B-155/B-155.hpp"
#include "T-9/B-156/B-156.hpp"

// TREE 11
#include "T-11/B-158/B-158.hpp"
#include "T-11/B-159/B-159.hpp"
#include "T-11/B-160/B-160.hpp"
#include "T-11/B-161/B-161.hpp"
#include "T-11/B-162/B-162.hpp"
#include "T-11/B-163/B-163.hpp"
#include "T-11/B-164/B-164.hpp"
#include "T-11/B-165/B-165.hpp"
#include "T-11/B-167/B-167.hpp"
#include "T-11/B-168/B-168.hpp"
#include "T-11/B-170/B-170.hpp"
#include "T-11/B-172/B-172.hpp"
#include "T-11/B-173/B-173.hpp"
#include "T-11/B-174/B-174.hpp"
#include "T-11/B-175/B-175.hpp"

// TREE 13
#include "T-13/B-177/B-177.hpp"
#include "T-13/B-178/B-178.hpp"
#include "T-13/B-179/B-179.hpp"
#include "T-13/B-180/B-180.hpp"
#include "T-13/B-181/B-181.hpp"
#include "T-13/B-182/B-182.hpp"
#include "T-13/B-183/B-183.hpp"

// TREE 14
#include "T-14/B-184/B-184.hpp"
#include "T-14/B-185/B-185.hpp"
#include "T-14/B-187/B-187.hpp"
#include "T-14/B-188/B-188.hpp"
#include "T-14/B-189/B-189.hpp"
#include "T-14/B-192/B-192.hpp"
#include "T-14/B-193/B-193.hpp"
#include "T-14/B-195/B-195.hpp"
#include "T-14/B-196/B-196.hpp"
#include "T-14/B-197/B-197.hpp"
#include "T-14/B-198/B-198.hpp"
#include "T-14/B-199/B-199.hpp"
#include "T-14/B-200/B-200.hpp"
#include "T-14/B-201/B-201.hpp"
#include "T-14/B-202/B-202.hpp"
#include "T-14/B-203/B-203.hpp"
#include "T-14/B-205/B-205.hpp"
#include "T-14/B-206/B-206.hpp"
#include "T-14/B-207/B-207.hpp"

Behaviour * Behaviour::get(const talkers::BehaviourID behaviourID) {
    switch (behaviourID) {

        // TREE 1
        case 1: return new B1();
        case 3: return new B3();
        case 4: return new B4();
        case 5: return new B5();
        case 6: return new B6();
        case 7: return new B7();
        case 8: return new B8();
        case 9: return new B9();
        case 10: return new B10();
        case 12: return new B12();
        case 13: return new B13();
        case 14: return new B14();
        case 15: return new B15();
        case 16: return new B16();

        // TREE 2
        case 11: return new B11();
        case 17: return new B17();
        case 20: return new B20();
        case 21: return new B21();

        // TREE 3
        case 18: return new B18();
        case 23: return new B23();
        case 48: return new B48();
        case 49: return new B49();
        case 55: return new B55();
        case 59: return new B59();
        case 61: return new B61();
        case 62: return new B62();
        case 63: return new B63();
        case 64: return new B64();
        case 65: return new B65();
        case 67: return new B67();
        case 68: return new B68();
        case 69: return new B69();
        case 71: return new B71();
        case 72: return new B72();
        case 73: return new B73();
        case 75: return new B75();
        case 76: return new B76();
        case 77: return new B77();
        case 78: return new B78();
        case 80: return new B80();
        case 82: return new B82();
        case 85: return new B85();
        case 86: return new B86();
        case 88: return new B88();
        case 89: return new B89();

        // TREE 4
        case 22: return new B22();
        case 47: return new B47();

        // TREE 5
        case 50: return new B50();
        case 52: return new B52();
        case 53: return new B53();
        case 54: return new B54();
        case 56: return new B56();
        case 57: return new B57();
        case 58: return new B58();
        case 60: return new B60();
        case 70: return new B70();
        case 81: return new B81();
        case 83: return new B83();
        case 84: return new B84();
        case 87: return new B87();
        case 90: return new B90();
        case 91: return new B91();
        case 92: return new B92();
        case 93: return new B93();
        case 94: return new B94();
        case 95: return new B95();
        case 96: return new B96();
        case 97: return new B97();
        case 98: return new B98();

        // TREE 6
        case 99: return new B99();
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
        case 114: return new B114();
        case 115: return new B115();
        case 116: return new B116();
        case 117: return new B117();
        case 118: return new B118();
        case 119: return new B119();
        case 120: return new B120();
        case 121: return new B121();
        case 122: return new B122();
        case 123: return new B123();
        case 124: return new B124();
        case 125: return new B125();
        case 126: return new B126();
        case 127: return new B127();

        // TREE 7
        case 128: return new B128();
        case 129: return new B129();
        case 130: return new B130();
        case 131: return new B131();
        case 132: return new B132();
        case 133: return new B133();
        case 135: return new B135();

        // TREE 9
        case 139: return new B139();
        case 141: return new B141();
        case 142: return new B142();
        case 144: return new B144();
        case 145: return new B145();
        case 146: return new B146();
        case 147: return new B147();
        case 148: return new B148();
        case 149: return new B149();
        case 151: return new B151();
        case 152: return new B152();
        case 153: return new B153();
        case 155: return new B155();
        case 156: return new B156();

        // TREE 11
        case 158: return new B158();
        case 159: return new B159();
        case 160: return new B160();
        case 161: return new B161();
        case 162: return new B162();
        case 163: return new B163();
        case 164: return new B164();
        case 165: return new B165();
        case 167: return new B167();
        case 168: return new B168();
        case 170: return new B170();
        case 172: return new B172();
        case 173: return new B173();
        case 174: return new B174();
        case 175: return new B175();

        // TREE 13
        case 177: return new B177();
        case 178: return new B178();
        case 179: return new B179();
        case 180: return new B180();
        case 181: return new B181();
        case 182: return new B182();
        case 183: return new B183();

        // TREE 14
        case 184: return new B184();
        case 185: return new B185();
        case 187: return new B187();
        case 188: return new B188();
        case 189: return new B189();
        case 192: return new B192();
        case 193: return new B193();
        case 195: return new B195();
        case 196: return new B196();
        case 197: return new B197();
        case 198: return new B198();
        case 199: return new B199();
        case 200: return new B200();
        case 201: return new B201();
        case 202: return new B202();
        case 203: return new B203();
        case 205: return new B205();
        case 206: return new B206();
        case 207: return new B207();

        default:
            LOG_ERROR("*** No behaviour #" + std::to_string(behaviourID));
            return nullptr;
    }
}
