//
//  S-211-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_211_00_hpp
#define S_211_00_hpp

#include "../../Output.hpp"

class S21100: public Output {
public:

	S21100(): Output(21100,	// Output ID
					 false,	// Is tree end ?
					 212,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Je n’ai rien de mon côté. C’est peut-être une erreur."
	}) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_211_00_hpp */
