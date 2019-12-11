//
//  S-803-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_803_00_hpp
#define S_803_00_hpp

#include "../../Output.hpp"

class S80300 : public Output {
public:

	S80300() : Output(80300,	// Output ID
		false,	// Is tree end ?
		804,	// Next Behaviour ID
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

#endif /* S_803_00_hpp */
