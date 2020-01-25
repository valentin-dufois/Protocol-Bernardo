//
//  S-309-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_309_00_hpp
#define S_309_00_hpp

#include "../../Output.hpp"

class S30900: public Output {
public:

	S30900(): Output(30900,	// Output ID
					 false,	// Is tree end ?
					 310,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Discuter ?"
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_309_00_hpp */
