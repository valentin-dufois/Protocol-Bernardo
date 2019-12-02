//
//  S-100-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_100_00_hpp
#define S_100_00_hpp

#include "../Output.hpp"

class S10000: public Output {
public:

	virtual bool isConditionValid(const State &behaviourState);

protected:
	
	std::vector<std::string> _outputValues = {
		"NBR_BODY"
	};

	std::vector<std::string> _captions = {
		"Bien que je détecte {NBR_BODY} personne.s, je ne détecte pas de mouvement."
	};

	bool _isTreeEnd = false;

	unsigned int _nextBehaviour = 101;

	bool _isDelayed = false;

	double _delayValue = 0;

	double _delayVariance = 0;
};

#endif /* S_100_00_hpp */
