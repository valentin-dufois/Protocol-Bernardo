//
//  S-219-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_219_00_hpp
#define S_219_00_hpp

#include "../../Output.hpp"

class S21900: public Output {
public:

	S21900(): Output(21900,	// Output ID
					 false,	// Is tree end ?
					 220,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"J’ai bien peur que non."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_219_00_hpp */
