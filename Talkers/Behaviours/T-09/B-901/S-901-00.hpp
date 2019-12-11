//
//  S-901-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_901_00_hpp
#define S_901_00_hpp

#include "../../Output.hpp"

class S90100 : public Output {
public:
	S90100() : Output(90100,					// Output ID
		true,					// Is tree end ?
		902,					// Next Behaviour ID
		DELAY_DEFAULT,			// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
		{						// Output values
		},
					 {						// Captions
		"C'est fait.",
		"C'est déjà fait."
					 }) {}

	inline bool isConditionValid(const State &behaviourState) {
		return true;
	};
};

#endif /* S_901_00_hpp */
