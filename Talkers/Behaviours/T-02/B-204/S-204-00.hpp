//
//  S-204-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_204_00_hpp
#define S_204_00_hpp

#include "../../Output.hpp"

class S20400: public Output {
public:

	S20400(): Output(20400,	// Output ID
					 false,	// Is tree end ?
					 205,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Intéressant."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_204_00_hpp */
