//
//  S-312-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_312_00_hpp
#define S_312_00_hpp

#include "../../Output.hpp"

class S31200: public Output {
public:

	S31200(): Output(31200,	// Output ID
					 false,	// Is tree end ?
					 313,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Va savoir."
	}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_312_00_hpp */
