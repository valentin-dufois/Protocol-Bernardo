//
//  S-317-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_317_00_hpp
#define S_317_00_hpp

#include "../../Output.hpp"

class S31700: public Output {
public:

	S31700(): Output(31700,	// Output ID
					 true,	// Is tree end ?
					 -1,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Je ne sais pas."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_317_00_hpp */
