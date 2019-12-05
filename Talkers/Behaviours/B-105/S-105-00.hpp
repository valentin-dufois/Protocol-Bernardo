//
//  S-105-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_105_00_hpp
#define S_105_00_hpp

#include "../Output.hpp"

class S10500 : public Output {
public:
	S10500(): Output(10500,					// Output ID
					 false,					// Is tree end ?
					 106,					// Next Behaviour ID
					 DELAY_DEFAULT,			// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
					 {						// Output values
	},
					 {						// Captions
		"Tu poses beaucoup de questions."
	}) {}

	inline bool isConditionValid(const State &behaviourState) {
		return true;
	};
};

#endif /* S_105_00_hpp */
