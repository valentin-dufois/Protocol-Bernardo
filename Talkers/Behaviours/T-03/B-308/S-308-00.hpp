//
//  S-308-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_308_00_hpp
#define S_308_00_hpp

#include "../../Output.hpp"

class S30800: public Output {
public:

	S30800(): Output(30800,	// Output ID
					 false,	// Is tree end ?
					 309,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Peut-être qu'elles discutent."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_308_00_hpp */
