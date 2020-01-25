//
//  S-208-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_209_00_hpp
#define S_209_00_hpp

#include "../../Output.hpp"

class S20900: public Output {
public:

	S20900(): Output(20900,	// Output ID
					 true,	// Is tree end ?
					 -1,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Je m'occuperai des calculs."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_209_00_hpp */
