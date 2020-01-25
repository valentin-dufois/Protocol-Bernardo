//
//  S-208-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_208_00_hpp
#define S_208_00_hpp

#include "../../Output.hpp"

class S20800: public Output {
public:

	S20800(): Output(20800,	// Output ID
					 false,	// Is tree end ?
					 209,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Ah oui ?"
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_208_00_hpp */
