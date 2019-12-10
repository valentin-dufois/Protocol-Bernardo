//
//  S-509-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_509_00_hpp
#define S_509_00_hpp

#include "../../Output.hpp"

class S50900 : public Output {
public:

	S50900() : Output(50900,	// Output ID
		false,	// Is tree end ?
		510, 	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Je ne sais pas. Notre but semble être défini dans ce seul espace."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_509_00_hpp */
