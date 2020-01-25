//
//  S-513-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_513_00_hpp
#define S_513_00_hpp

#include "../../Output.hpp"

class S51300 : public Output {
public:

	S51300() : Output(51300,	// Output ID
		false,	// Is tree end ?
		514, 	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Quel est notre but ?"
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_513_00_hpp */
