//
//  S-600-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_600_00_hpp
#define S_600_00_hpp

#include "../../Output.hpp"

class S60000 : public Output {
public:

	S60000() : Output(60000,	// Output ID
		false,	// Is tree end ?
		601,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
			"TOTAL_BODY_COUNT"
		},
					 {		// Captions
		"Jusqu'ici, j'ai compté {TOTAL_BODY_COUNT} personnes présentes, au total."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		_state.insert_or_assign("TOTAL_BODY_COUNT", behaviourState.at("TOTAL_BODY_COUNT"));
		return true;
	};
};

#endif /* S_600_00_hpp */
