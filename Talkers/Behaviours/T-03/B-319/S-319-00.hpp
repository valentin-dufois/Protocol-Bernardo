//
//  S-319-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_319_00_hpp
#define S_319_00_hpp

#include "../../Output.hpp"

class S31900: public Output {
public:

	S31900(): Output(31900,	// Output ID
					 true,	// Is tree end ?
					 -1,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Peut-être."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_319_00_hpp */
