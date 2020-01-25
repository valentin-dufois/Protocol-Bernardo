//
//  S-824-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_824_00_hpp
#define S_824_00_hpp

#include "../../Output.hpp"

class S82400 : public Output {
public:

	S82400() : Output(82400,	// Output ID
		true,	// Is tree end ?
		825,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Tu veux dire que ce sont les mêmes, ou bien que tous ont des comportements similaires ?"
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_824_00_hpp */
