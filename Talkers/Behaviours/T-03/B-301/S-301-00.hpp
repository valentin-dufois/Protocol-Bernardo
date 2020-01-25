//
//  S-301-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_301_00_hpp
#define S_301_00_hpp

#include "../../Output.hpp"

class S30100: public Output {
public:

	S30100(): Output(30100,	// Output ID
					 false,	// Is tree end ?
					 302,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Qu'est ce que ça peut bien vouloir dire ?"
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_301_00_hpp */
