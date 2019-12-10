//
//  S-504-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_504_00_hpp
#define S_504_00_hpp

#include "../../Output.hpp"

class S50400 : public Output {
public:

	S50400() : Output(50400,	// Output ID
		false,	// Is tree end ?
		505, 	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Cette question t'intéresse t-elle ?"
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_505_00_hpp */
