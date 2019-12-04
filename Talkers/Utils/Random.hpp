//
//  Random.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-27.
//

#ifndef Random_h
#define Random_h

// thx https://stackoverflow.com/questions/6942273/how-to-get-a-random-element-from-a-c-container

#include  <random>
#include  <iterator>

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
	std::uniform_int_distribution<> dis(0, (int)std::distance(start, end) - 1);
	std::advance(start, dis(g));
	return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	return select_randomly(start, end, gen);
}

#endif /* Random_h */
