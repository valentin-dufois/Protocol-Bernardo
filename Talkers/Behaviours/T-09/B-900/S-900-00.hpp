//
//  S-900-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_900_00_hpp
#define S_900_00_hpp

#include "../../Output.hpp"

class S90000 : public Output {
public:
	S90000() : Output(90000,					// Output ID
		false,					// Is tree end ?
		901,					// Next Behaviour ID
		DELAY_DEFAULT,			// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
		{						// Output values
		},
					 {						// Captions
		"Enregistre-le.",
		"Conserve ces données."
					 }) {}

	inline bool isConditionValid(State &behaviourState) {
		return true;
	};
};

#endif /* S_900_00_hpp */
