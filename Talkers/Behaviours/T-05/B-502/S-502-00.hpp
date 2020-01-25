//
//  S-502-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_502_00_hpp
#define S_502_00_hpp

#include "../../Output.hpp"

class S50200 : public Output {
public:

	S50200() : Output(50200,	// Output ID
		false,	// Is tree end ?
		503, 	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Ta réponse peut-elle être plus précise ?"
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_502_00_hpp */
