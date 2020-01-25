//
//  S-800-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_800_00_hpp
#define S_800_00_hpp

#include "../../Output.hpp"

class S80000 : public Output {
public:

	S80000() : Output(80000,	// Output ID
		false,	// Is tree end ?
		801,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Penses-tu que les personnes présentes dans cette salle savent ce qui s'y déroule ?"
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_800_00_hpp */
