//
//  S-112-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_113_00_hpp
#define S_113_00_hpp

#include "../Output.hpp"

class S11300 : public Output {
public:
	S11300(): Output(11300,					// Output ID
					 true,					// Is tree end ?
					 -1,					// Next Behaviour ID
					 DELAY_DEFAULT,			// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
					 {						// Output values
	},
					 {						// Captions
		"Parfait."
	}) {}

	inline bool isConditionValid(const State &behaviourState) {
		return true;
	};
};

#endif /* S_112_00_hpp */
