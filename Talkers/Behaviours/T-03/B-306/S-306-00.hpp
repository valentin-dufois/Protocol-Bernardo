//
//  S-306-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_306_00_hpp
#define S_306_00_hpp

#include "../../Output.hpp"

class S30600: public Output {
public:

	S30600(): Output(30600,	// Output ID
					 false,	// Is tree end ?
					 307,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Éventuellement."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_306_00_hpp */
