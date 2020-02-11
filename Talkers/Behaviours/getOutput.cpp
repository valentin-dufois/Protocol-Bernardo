//
//  getOutput.cpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#include "Output.hpp"
#include "../../Common/Utils/Log.hpp"

#include <iostream>

// TREE 1
#include "T-1/B-1/O-1.hpp"
#include "T-1/B-1/O-9999.hpp"
#include "T-1/B-3/O-2.hpp"
#include "T-1/B-4/O-3.hpp"
#include "T-1/B-5/O-4.hpp"
#include "T-1/B-6/O-5.hpp"
#include "T-1/B-7/O-6.hpp"
#include "T-1/B-8/O-7.hpp"
#include "T-1/B-9/O-8.hpp"
#include "T-1/B-10/O-9.hpp"
#include "T-1/B-12/O-10.hpp"
#include "T-1/B-13/O-13.hpp"
#include "T-1/B-14/O-14.hpp"
#include "T-1/B-15/O-15.hpp"
#include "T-1/B-16/O-16.hpp"

// TREE 2
#include "T-2/B-11/O-11.hpp"
#include "T-2/B-17/O-17.hpp"
#include "T-2/B-20/O-20.hpp"
#include "T-2/B-21/O-22.hpp"

// TREE 3
#include "T-3/B-18/O-18.hpp"
#include "T-3/B-18/O-19.hpp"
#include "T-3/B-18/O-21.hpp"
#include "T-3/B-23/O-24.hpp"
#include "T-3/B-23/O-25.hpp"
#include "T-3/B-48/O-29.hpp"
#include "T-3/B-49/O-30.hpp"
#include "T-3/B-55/O-35.hpp"
#include "T-3/B-59/O-39.hpp"
#include "T-3/B-61/O-41.hpp"
#include "T-3/B-62/O-42.hpp"
#include "T-3/B-63/O-43.hpp"
#include "T-3/B-64/O-44.hpp"
#include "T-3/B-65/O-46.hpp"
#include "T-3/B-67/O-47.hpp"
#include "T-3/B-68/O-48.hpp"
#include "T-3/B-69/O-49.hpp"
#include "T-3/B-71/O-51.hpp"
#include "T-3/B-72/O-52.hpp"
#include "T-3/B-73/O-53.hpp"
#include "T-3/B-75/O-54.hpp"
#include "T-3/B-76/O-56.hpp"
#include "T-3/B-77/O-57.hpp"
#include "T-3/B-78/O-58.hpp"
#include "T-3/B-80/O-60.hpp"
#include "T-3/B-82/O-62.hpp"
#include "T-3/B-85/O-65.hpp"
#include "T-3/B-86/O-66.hpp"
#include "T-3/B-88/O-68.hpp"
#include "T-3/B-89/O-69.hpp"

// TREE 4
#include "T-4/B-22/O-26.hpp"
#include "T-4/B-47/O-27.hpp"
#include "T-4/B-47/O-28.hpp"

// TREE 5
#include "T-5/B-50/O-31.hpp"
#include "T-5/B-52/O-32.hpp"
#include "T-5/B-53/O-33.hpp"
#include "T-5/B-54/O-34.hpp"
#include "T-5/B-56/O-36.hpp"
#include "T-5/B-57/O-37.hpp"
#include "T-5/B-58/O-38.hpp"
#include "T-5/B-60/O-40.hpp"
#include "T-5/B-60/O-45.hpp"
#include "T-5/B-70/O-50.hpp"
#include "T-5/B-81/O-61.hpp"
#include "T-5/B-83/O-63.hpp"
#include "T-5/B-84/O-64.hpp"
#include "T-5/B-87/O-67.hpp"
#include "T-5/B-90/O-70.hpp"
#include "T-5/B-91/O-71.hpp"
#include "T-5/B-91/O-9998.hpp"
#include "T-5/B-91/O-72.hpp"
#include "T-5/B-92/O-73.hpp"
#include "T-5/B-93/O-74.hpp"
#include "T-5/B-94/O-75.hpp"
#include "T-5/B-95/O-76.hpp"
#include "T-5/B-96/O-77.hpp"
#include "T-5/B-97/O-78.hpp"
#include "T-5/B-98/O-79.hpp"

// TREE 6
#include "T-6/B-99/O-80.hpp"
#include "T-6/B-100/O-81.hpp"
#include "T-6/B-101/O-82.hpp"
#include "T-6/B-102/O-83.hpp"
#include "T-6/B-103/O-84.hpp"
#include "T-6/B-104/O-85.hpp"
#include "T-6/B-105/O-86.hpp"
#include "T-6/B-106/O-87.hpp"
#include "T-6/B-107/O-88.hpp"
#include "T-6/B-108/O-89.hpp"
#include "T-6/B-109/O-91.hpp"
#include "T-6/B-110/O-92.hpp"
#include "T-6/B-111/O-93.hpp"
#include "T-6/B-112/O-94.hpp"
#include "T-6/B-113/O-96.hpp"
#include "T-6/B-113/O-97.hpp"
#include "T-6/B-114/O-98.hpp"
#include "T-6/B-115/O-99.hpp"
#include "T-6/B-116/O-100.hpp"
#include "T-6/B-117/O-102.hpp"
#include "T-6/B-118/O-103.hpp"
#include "T-6/B-119/O-104.hpp"
#include "T-6/B-120/O-105.hpp"
#include "T-6/B-121/O-106.hpp"
#include "T-6/B-122/O-107.hpp"
#include "T-6/B-123/O-108.hpp"
#include "T-6/B-124/O-109.hpp"
#include "T-6/B-125/O-110.hpp"
#include "T-6/B-126/O-111.hpp"
#include "T-6/B-127/O-112.hpp"

// TREE 7
#include "T-7/B-128/O-113.hpp"
#include "T-7/B-129/O-114.hpp"
#include "T-7/B-130/O-115.hpp"
#include "T-7/B-131/O-116.hpp"
#include "T-7/B-132/O-118.hpp"
#include "T-7/B-132/O-119.hpp"
#include "T-7/B-133/O-120.hpp"
#include "T-7/B-135/O-121.hpp"

// TREE 9
#include "T-9/B-139/O-127.hpp"
#include "T-9/B-139/O-9997.hpp"
#include "T-9/B-141/O-128.hpp"
#include "T-9/B-141/O-129.hpp"
#include "T-9/B-142/O-130.hpp"
#include "T-9/B-144/O-131.hpp"
#include "T-9/B-145/O-133.hpp"
#include "T-9/B-146/O-135.hpp"
#include "T-9/B-147/O-136.hpp"
#include "T-9/B-148/O-138.hpp"
#include "T-9/B-149/O-140.hpp"
#include "T-9/B-151/O-142.hpp"
#include "T-9/B-152/O-144.hpp"
#include "T-9/B-153/O-146.hpp"
#include "T-9/B-155/O-148.hpp"
#include "T-9/B-156/O-149.hpp"

// TREE 11
#include "T-11/B-158/O-151.hpp"
#include "T-11/B-159/O-154.hpp"
#include "T-11/B-160/O-155.hpp"
#include "T-11/B-161/O-156.hpp"
#include "T-11/B-162/O-157.hpp"
#include "T-11/B-163/O-158.hpp"
#include "T-11/B-164/O-160.hpp"
#include "T-11/B-165/O-162.hpp"
#include "T-11/B-167/O-164.hpp"
#include "T-11/B-168/O-166.hpp"
#include "T-11/B-170/O-167.hpp"
#include "T-11/B-172/O-169.hpp"
#include "T-11/B-173/O-171.hpp"
#include "T-11/B-174/O-172.hpp"
#include "T-11/B-175/O-174.hpp"

// TREE 13
#include "T-13/B-177/O-176.hpp"
#include "T-13/B-178/O-177.hpp"
#include "T-13/B-179/O-179.hpp"
#include "T-13/B-180/O-181.hpp"
#include "T-13/B-181/O-182.hpp"
#include "T-13/B-182/O-183.hpp"
#include "T-13/B-183/O-185.hpp"

// TREE 14
#include "T-14/B-184/O-187.hpp"
#include "T-14/B-185/O-188.hpp"
#include "T-14/B-187/O-189.hpp"
#include "T-14/B-188/O-191.hpp"
#include "T-14/B-189/O-193.hpp"
#include "T-14/B-192/O-195.hpp"
#include "T-14/B-193/O-197.hpp"
#include "T-14/B-193/O-199.hpp"
#include "T-14/B-195/O-200.hpp"
#include "T-14/B-196/O-201.hpp"
#include "T-14/B-197/O-203.hpp"
#include "T-14/B-198/O-204.hpp"
#include "T-14/B-199/O-205.hpp"
#include "T-14/B-200/O-206.hpp"
#include "T-14/B-201/O-207.hpp"
#include "T-14/B-202/O-208.hpp"
#include "T-14/B-203/O-210.hpp"
#include "T-14/B-205/O-211.hpp"
#include "T-14/B-206/O-212.hpp"
#include "T-14/B-207/O-213.hpp"

Output * Output::get(const talkers::OutputID id) {
    switch (id) {

        // TREE 1
        case 1: return new O1();
		case 9999: return new O9999();
        case 2: return new O2();
        case 3: return new O3();
        case 4: return new O4();
        case 5: return new O5();
        case 6: return new O6();
        case 7: return new O7();
        case 8: return new O8();
        case 9: return new O9();
        case 10: return new O10();
        case 13: return new O13();
        case 14: return new O14();
        case 15: return new O15();
        case 16: return new O16();

        // TREE 2
        case 11: return new O11();
        case 17: return new O17();
        case 20: return new O20();
        case 22: return new O22();

        // TREE 3
        case 18: return new O18();
        case 19: return new O19();
        case 21: return new O21();
        case 24: return new O24();
        case 25: return new O25();
        case 29: return new O29();
        case 30: return new O30();
        case 35: return new O35();
        case 39: return new O39();
        case 41: return new O41();
        case 42: return new O42();
        case 43: return new O43();
        case 44: return new O44();
        case 46: return new O46();
        case 47: return new O47();
        case 48: return new O48();
        case 49: return new O49();
        case 51: return new O51();
        case 52: return new O52();
        case 53: return new O53();
        case 54: return new O54();
        case 56: return new O56();
        case 57: return new O57();
        case 58: return new O58();
        case 60: return new O60();
        case 62: return new O62();
        case 65: return new O65();
        case 66: return new O66();
        case 68: return new O68();
        case 69: return new O69();

        // TREE 4
        case 26: return new O26();
        case 27: return new O27();
        case 28: return new O28();

        // TREE 5
        case 31: return new O31();
        case 32: return new O32();
        case 33: return new O33();
        case 34: return new O34();
        case 36: return new O36();
        case 37: return new O37();
        case 38: return new O38();
        case 40: return new O40();
        case 45: return new O45();
        case 50: return new O50();
        case 61: return new O61();
        case 63: return new O63();
        case 64: return new O64();
        case 67: return new O67();
        case 70: return new O70();
		case 71: return new O71();
		case 9998: return new O9998();
        case 72: return new O72();
        case 73: return new O73();
        case 74: return new O74();
        case 75: return new O75();
        case 76: return new O76();
        case 77: return new O77();
        case 78: return new O78();
        case 79: return new O79();

        // TREE 6
        case 80: return new O80();
        case 81: return new O81();
        case 82: return new O82();
        case 83: return new O83();
        case 84: return new O84();
        case 85: return new O85();
        case 86: return new O86();
        case 87: return new O87();
        case 88: return new O88();
        case 89: return new O89();
        case 91: return new O91();
        case 92: return new O92();
        case 93: return new O93();
        case 94: return new O94();
        case 96: return new O96();
        case 97: return new O97();
        case 98: return new O98();
        case 99: return new O99();
        case 100: return new O100();
        case 102: return new O102();
        case 103: return new O103();
        case 104: return new O104();
        case 105: return new O105();
        case 106: return new O106();
        case 107: return new O107();
        case 108: return new O108();
        case 109: return new O109();
        case 110: return new O110();
        case 111: return new O111();
        case 112: return new O112();

        // TREE 7
        case 113: return new O113();
        case 114: return new O114();
        case 115: return new O115();
        case 116: return new O116();
        case 118: return new O118();
        case 119: return new O119();
        case 120: return new O120();
        case 121: return new O121();

        // TREE 9
        case 127: return new O127();
		case 9997: return new O9997();
        case 128: return new O128();
        case 129: return new O129();
        case 130: return new O130();
        case 131: return new O131();
        case 133: return new O133();
        case 135: return new O135();
        case 136: return new O136();
        case 138: return new O138();
        case 140: return new O140();
        case 142: return new O142();
        case 144: return new O144();
        case 146: return new O146();
        case 148: return new O148();
        case 149: return new O149();

        // TREE 11
        case 151: return new O151();
        case 154: return new O154();
        case 155: return new O155();
        case 156: return new O156();
        case 157: return new O157();
        case 158: return new O158();
        case 160: return new O160();
        case 162: return new O162();
        case 164: return new O164();
        case 166: return new O166();
        case 167: return new O167();
        case 169: return new O169();
        case 171: return new O171();
        case 172: return new O172();
        case 174: return new O174();

        // TREE 13
        case 176: return new O176();
        case 177: return new O177();
        case 179: return new O179();
        case 181: return new O181();
        case 182: return new O182();
        case 183: return new O183();
        case 185: return new O185();

        // TREE 14
        case 187: return new O187();
        case 188: return new O188();
        case 189: return new O189();
        case 191: return new O191();
        case 193: return new O193();
        case 195: return new O195();
        case 197: return new O197();
        case 199: return new O199();
        case 200: return new O200();
        case 201: return new O201();
        case 203: return new O203();
        case 204: return new O204();
        case 205: return new O205();
        case 206: return new O206();
        case 207: return new O207();
        case 208: return new O208();
        case 210: return new O210();
        case 211: return new O211();
        case 212: return new O212();
        case 213: return new O213();

        default:
            LOG_ERROR("*** No behaviour #" + std::to_string(id));
            return nullptr;
    }
}
