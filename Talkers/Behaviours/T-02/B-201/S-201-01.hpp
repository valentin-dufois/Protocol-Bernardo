//
//  S-201-01.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_201_01_hpp
#define S_201_01_hpp

#include "../../Output.hpp"

class S20101: public Output {
public:

	S20101(): Output(20101,	// Output ID
					 false,	// Is tree end ?
					 210,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Non, quoi donc ?"
	}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return !behaviourState.at("SUDDEN_MOVE").getBool();
	};
};

#endif /* S_201_01_hpp */
