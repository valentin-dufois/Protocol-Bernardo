//
//  S-215-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_215_00_hpp
#define S_215_00_hpp

#include "../../Output.hpp"

class S21500: public Output {
public:

	S21500(): Output(21500,	// Output ID
					 false,	// Is tree end ?
					 216,	// Next Behaviour ID
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

#endif /* S_215_00_hpp */
