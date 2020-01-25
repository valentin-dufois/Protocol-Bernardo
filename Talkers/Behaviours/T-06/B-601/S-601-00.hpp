//
//  S-601-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_601_00_hpp
#define S_601_00_hpp

#include "../../Output.hpp"

class S60100 : public Output {
public:

	S60100() : Output(60100,	// Output ID
		false,	// Is tree end ?
		602,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
		{		// Captions
			"C'est relativement peu."
		}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return std::get<int>(behaviourState["TOTAL_BODY_COUNT"]) < 10;
	};
};

#endif /* S_601_00_hpp */
