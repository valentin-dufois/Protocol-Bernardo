
//
//  main.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-04.
//

#ifndef main_h
#define main_h

#include <variant>
#include <string>
#include <map>

namespace talkers {
using BehaviourID = short int;
using OutputID = int;
using TreeID = short int;
}

using State = std::map<std::string, std::variant<int, double, bool, std::string>>;


#endif /* main_h */
