//
//  S-100-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_100_00_hpp
#define S_100_00_hpp

#include "../../Output.hpp"

class S10000: public Output {
public:

	S10000(): Output(10000,	// Output ID
					 false,	// Is tree end ?
					 101,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
		"NBR_BODY"
	},
					 {		// Captions
		"Bien que je détecte une personne, je ne détecte pas de mouvement."
	}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		_state.insert_or_assign("NBR_BODY", behaviourState.at("NBR_BODY"));

		return _state.at("NBR_BODY").getInt() == 1;
	};
};

#endif /* S_100_00_hpp */
