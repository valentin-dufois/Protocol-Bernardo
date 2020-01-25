//
//  S-217-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_217_00_hpp
#define S_217_00_hpp

#include "../../Output.hpp"

class S21700: public Output {
public:

	S21700(): Output(21700,	// Output ID
					 false,	// Is tree end ?
					 218,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"En effet."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_217_00_hpp */
