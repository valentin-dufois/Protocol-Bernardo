//
//  S-700-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_700_00_hpp
#define S_700_00_hpp

#include "../../Output.hpp"

class S70000 : public Output {
public:

	S70000() : Output(70000,	// Output ID
		false,	// Is tree end ?
		701,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Il y a quelqu'un qui est très proche.",
		"Une personne s'est beaucoup rapprochée.",
		"Je capte quelqu'un qui est très proche."
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_700_00_hpp */
