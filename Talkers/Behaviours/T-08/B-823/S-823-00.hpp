//
//  S-823-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_823_00_hpp
#define S_823_00_hpp

#include "../../Output.hpp"

class S82300 : public Output {
public:

	S82300() : Output(82300,	// Output ID
		true,	// Is tree end ?
		824,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"J'ai remarqué certaines similitudes dans leurs comportements. C'est donc une possibilité."
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_823_00_hpp */
