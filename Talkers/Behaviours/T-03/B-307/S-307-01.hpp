//
//  S-307-01.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_307_01_hpp
#define S_307_01_hpp

#include "../../Output.hpp"

class S30701: public Output {
public:

	S30701(): Output(30701,	// Output ID
					 false,	// Is tree end ?
					 314,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Elles se sont séparées."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return !std::get<bool>(behaviourState["STILL_CLOSE"]);
	};
};

#endif /* S_307_01_hpp */
