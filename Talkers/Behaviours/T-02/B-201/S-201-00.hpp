//
//  S-201-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_201_00_hpp
#define S_201_00_hpp

#include "../../Output.hpp"

class S20100: public Output {
public:

	S20100(): Output(20100,	// Output ID
					 false,	// Is tree end ?
					 202,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Oui. C’était soudain. Une personne s’est certainement déplacée rapidement."
	}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return behaviourState.at("SUDDEN_MOVE").getBool();
	};
};

#endif /* S_201_00_hpp */
