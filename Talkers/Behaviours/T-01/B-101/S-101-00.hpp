//
//  S-101-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_101_00_hpp
#define S_101_00_hpp

#include "../../Output.hpp"

class S10100: public Output {
public:

	S10100(): Output(10100,						// Output ID
					 false,						// Is tree end ?
					 102,						// Next Behaviour ID
					 DELAY_DEFAULT,				// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
					 {							// Output values
	},
					 {							// Captions
		"Les personnes présentes ont stabilisé leur position en même temps. Intéressant."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_101_00_hpp */
