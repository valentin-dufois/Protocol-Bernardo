//
//  S-108-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_108_00_hpp
#define S_108_00_hpp

#include "../../Output.hpp"

class S10800 : public Output {
public:
	S10800(): Output(10800,					// Output ID
					 false,					// Is tree end ?
					 109,					// Next Behaviour ID
					 DELAY_DEFAULT,			// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
					 {						// Output values
	},
					 {						// Captions
		"Oui."
	}) {}

	inline bool isConditionValid(State &behaviourState) {
		return true;
	};
};

#endif /* S_108_00_hpp */
