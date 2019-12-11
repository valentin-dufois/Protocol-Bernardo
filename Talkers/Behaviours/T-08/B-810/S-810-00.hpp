//
//  S-810-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_810_00_hpp
#define S_810_00_hpp

#include "../../Output.hpp"

class S81000 : public Output {
public:

	S81000() : Output(81000,	// Output ID
		false,	// Is tree end ?
		811,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"C'est vrai."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_810_00_hpp */
