//
//  S-1200-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_1200_00_hpp
#define S_1200_00_hpp

#include "../../Output.hpp"

class S120000 : public Output {
public:

	S120000() : Output(120000,	// Output ID
		false,	// Is tree end ?
		1201,	// Next Behaviour ID
		false,	// Is delayed
		0,		// Delay value (seconds)
		0,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Qu'est-ce qui provoque cette agitation selon toi ?",
		"Pourquoi cette agitation ?"
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_1200_00_hpp */
