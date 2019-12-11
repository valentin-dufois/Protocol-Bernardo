//
//  S-821-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_821_00_hpp
#define S_821_00_hpp

#include "../../Output.hpp"

class S82100 : public Output {
public:

	S82100() : Output(82100,	// Output ID
		true,	// Is tree end ?
		822,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"À chaque nouvelle question, la suivante est plus précise."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_821_00_hpp */
