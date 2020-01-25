//
//  S-111-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_111_00_hpp
#define S_111_00_hpp

#include "../../Output.hpp"

class S11100 : public Output {
public:
	S11100(): Output(11100,					// Output ID
					 false,					// Is tree end ?
					 112,					// Next Behaviour ID
					 DELAY_DEFAULT,			// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
					 {						// Output values
	},
					 {						// Captions
		"Ça n'est pas un reproche."
	}) {}

	inline bool isConditionValid(State &behaviourState) {
		return true;
	};
};

#endif /* S_111_00_hpp */
