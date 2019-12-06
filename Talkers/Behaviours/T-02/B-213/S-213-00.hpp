//
//  S-213-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_213_00_hpp
#define S_213_00_hpp

#include "../../Output.hpp"

class S21300: public Output {
public:

	S21300(): Output(21300,	// Output ID
					 false,	// Is tree end ?
					 214,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Quand nos données concordent, j’imagine."
	}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_213_00_hpp */
