//
//  S-104-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_104_00_hpp
#define S_104_00_hpp

#include "../Output.hpp"

class S10400 : public Output {
public:
	S10400(): Output(10400,					// Output ID
					 false,					// Is tree end ?
					 105,					// Next Behaviour ID
					 DELAY_DEFAULT,			// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
					 {						// Output values
	},
					 {						// Captions
		"Si c'est le cas, dans quel but ?"
	}) {}

	inline bool isConditionValid(const State &behaviourState) {
		return true;
	};
};

#endif /* S_104_00_hpp */
