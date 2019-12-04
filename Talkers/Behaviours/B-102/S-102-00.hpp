//
//  S-100-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_102_00_hpp
#define S_102_00_hpp

#include "../Output.hpp"

class S10200 : public Output {
public:
	S10200(): Output(10200,					// Output ID
					 false,					// Is tree end ?
					 103,					// Next Behaviour ID
					 DELAY_DEFAULT,			// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
					 {						// Output values
	},
					 {						// Captions
		"Tu penses qu'elles l'ont fait intentionnellement ?"
	}) {}

	inline bool isConditionValid(const State &behaviourState) {
		return true;
	};
};

#endif /* S_100_00_hpp */
