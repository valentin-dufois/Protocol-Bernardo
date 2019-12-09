//
//  S-401-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_401_00_hpp
#define S_401_00_hpp

#include "../../Output.hpp"

class S40100 : public Output {
public:

	S40100() : Output(40100,	// Output ID
		false,	// Is tree end ?
		402,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Penses-tu que je pourrais t'etre utile ?",
		"Je pourrais peut-etre t'aider."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_401_00_hpp */
