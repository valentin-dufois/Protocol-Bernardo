//
//  S-110-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_110_00_hpp
#define S_110_00_hpp

#include "../../Output.hpp"

class S11000 : public Output {
public:
	S11000(): Output(11000,					// Output ID
					 false,					// Is tree end ?
					 111,					// Next Behaviour ID
					 DELAY_DEFAULT,			// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
					 {						// Output values
	},
					 {						// Captions
		"Et bien."
	}) {}

	inline bool isConditionValid(const State &behaviourState) {
		return true;
	};
};

#endif /* S_110_00_hpp */
