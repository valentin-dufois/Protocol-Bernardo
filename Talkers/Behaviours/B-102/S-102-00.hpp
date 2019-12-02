//
//  S-100-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_102_00_hpp
#define S_102_00_hpp

#include "../Output.hpp"

class S10200 : public Output {
public:

	inline bool isConditionValid(const State &behaviourState) { return true; };

protected:

	std::vector<std::string> _outputValues = {
	};

	std::vector<std::string> _captions = {
		"Tu penses qu'elles l'ont fait intentionnellement ?"
	};

	bool _isTreeEnd = false;

	unsigned int _nextBehaviour = 103;

	bool _isDelayed = false;

	double _delayValue = 0;

	double _delayVariance = 0;
};

#endif /* S_100_00_hpp */
