//
//  S-813-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_813_00_hpp
#define S_813_00_hpp

#include "../../Output.hpp"

class S81300 : public Output {
public:

	S81300() : Output(81300,	// Output ID
		false,	// Is tree end ?
		814,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Oui. Nous détectons des personnes, puis n'en détectons plus. J'interprète ainsi qu'elles vont et viennent."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_813_00_hpp */
