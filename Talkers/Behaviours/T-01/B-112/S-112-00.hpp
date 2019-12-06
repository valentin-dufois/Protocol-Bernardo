//
//  S-112-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_112_00_hpp
#define S_112_00_hpp

#include "../../Output.hpp"

class S11200 : public Output {
public:
	S11200(): Output(11200,					// Output ID
					 true,					// Is tree end ?
					 113,					// Next Behaviour ID
					 DELAY_DEFAULT,			// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,	// Delay variance (seconds)
					 {						// Output values
	},
					 {						// Captions
		"Je ne l'ai pas pris comme tel."
	}) {}

	inline bool isConditionValid(const State &behaviourState) {
		return true;
	};
};

#endif /* S_112_00_hpp */
