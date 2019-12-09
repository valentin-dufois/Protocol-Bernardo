//
//  S-305-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_305_00_hpp
#define S_305_00_hpp

#include "../../Output.hpp"

class S30500: public Output {
public:

	S30500(): Output(30500,	// Output ID
					 false,	// Is tree end ?
					 306,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Peut-être qu'elles se connaissent."
	}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_305_00_hpp */
