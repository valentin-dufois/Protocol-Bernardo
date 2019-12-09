//
//  S-316-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_316_00_hpp
#define S_316_00_hpp

#include "../../Output.hpp"

class S31600: public Output {
public:

	S31600(): Output(31600,	// Output ID
					 true,	// Is tree end ?
					 317,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Pourquoi donc ?"
	}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_316_00_hpp */
