//
//  S-304-01.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_304_01_hpp
#define S_304_01_hpp

#include "../../Output.hpp"

class S30401: public Output {
public:

	S30401(): Output(30401,	// Output ID
					 false,	// Is tree end ?
					 318,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
		"BODY_COUNT"
	},
					 {		// Captions
		"Non."
	}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		int bodyCount = behaviourState.at("BODY_COUNT").getInt();
		_state.insert_or_assign("BODY_COUNT", bodyCount);

		return bodyCount != 2;
	};
};

#endif /* S_304_01_hpp */
