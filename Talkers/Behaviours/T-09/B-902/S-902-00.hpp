//
//  S-902-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_902_00_hpp
#define S_902_00_hpp

#include "../../Output.hpp"

class S90200 : public Output {
public:
	S90200() : Output(90200,					// Output ID
		true,					// Is tree end ?
		-1,					// Next Behaviour ID
		DELAY_DEFAULT,			// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
		{						// Output values
		},
					 {						// Captions
		"Parfait.",
		"Très bien."
					 }) {}

	inline bool isConditionValid(State &behaviourState) {
		return true;
	};
};

#endif /* S_902_00_hpp */
