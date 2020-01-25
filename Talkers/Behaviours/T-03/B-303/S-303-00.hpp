//
//  S-303-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_303_00_hpp
#define S_303_00_hpp

#include "../../Output.hpp"

class S30300: public Output {
public:

	S30300(): Output(30300,	// Output ID
					 false,	// Is tree end ?
					 304,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Sont-elles seules ?"
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_303_00_hpp */
