//
//  S-106-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_106_00_hpp
#define S_106_00_hpp

#include "../../Output.hpp"

class S10600 : public Output {
public:
	S10600(): Output(10600,					// Output ID
					 false,					// Is tree end ?
					 107,					// Next Behaviour ID
					 DELAY_DEFAULT,			// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
					 {						// Output values
	},
					 {						// Captions
		"C'est un fait."
	}) {}

	inline bool isConditionValid(const State &behaviourState) {
		return true;
	};
};

#endif /* S_106_00_hpp */
