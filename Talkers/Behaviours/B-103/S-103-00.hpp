//
//  S-103-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_103_00_hpp
#define S_103_00_hpp

#include "../Output.hpp"

class S10300 : public Output {
public:
	S10300(): Output(10300,					// Output ID
					 false,					// Is tree end ?
					 104,					// Next Behaviour ID
					 DELAY_DEFAULT,			// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
					 {						// Output values
	},
					 {						// Captions
		"Peut être."
	}) {}

	inline bool isConditionValid(const State &behaviourState) {
		return true;
	};
};

#endif /* S_103_00_hpp */
