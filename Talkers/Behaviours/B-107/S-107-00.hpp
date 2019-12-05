//
//  S-107-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_107_00_hpp
#define S_107_00_hpp

#include "../Output.hpp"

class S10700 : public Output {
public:
	S10700(): Output(10700,					// Output ID
					 false,					// Is tree end ?
					 108,					// Next Behaviour ID
					 DELAY_DEFAULT,			// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
					 {						// Output values
	},
					 {						// Captions
		"Beaucoup de questions auxquelles je n'ai pas de réponses."
	}) {}

	inline bool isConditionValid(const State &behaviourState) {
		return true;
	};
};

#endif /* S_107_00_hpp */
