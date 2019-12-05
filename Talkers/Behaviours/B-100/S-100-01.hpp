//
//  S-100-01.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_100_01_hpp
#define S_100_01_hpp

#include "../Output.hpp"

class S10001: public Output {
public:

	S10001(): Output(10001,	// Output ID
					 false,	// Is tree end ?
					 101,	// Next Behaviour ID
					 false,	// Is delayed
					 0,		// Delay value (seconds)
					 0,		// Delay variance (seconds)
					 {		// Output values
		"NBR_BODY"
	},
					 {		// Captions
		"Bien que je détecte {NBR_BODY} personnes, je ne détecte pas de mouvement."
	}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		_state["NBR_BODY"] = behaviourState.at("NBR_BODY");

		return _state["NBR_BODY"].getInt() > 1;
	};
};

#endif /* S_100_00_hpp */
