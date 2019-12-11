//
//  S-809-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_809_00_hpp
#define S_809_00_hpp

#include "../../Output.hpp"

class S80900 : public Output {
public:

	S80900() : Output(80900,	// Output ID
		false,	// Is tree end ?
		810,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"L'endroit où nous nous trouvons semble n'être qu'un lieu de passage."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_809_00_hpp */
