//
//  S-817-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_817_00_hpp
#define S_817_00_hpp

#include "../../Output.hpp"

class S81700 : public Output {
public:

	S81700() : Output(81700,	// Output ID
		false,	// Is tree end ?
		818,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Je m'interroge sur la frustration que peut générer ce retour inlassable à notre point de départ."
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_817_00_hpp */
