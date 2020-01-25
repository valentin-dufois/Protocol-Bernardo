//
//  S-501-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_501_00_hpp
#define S_501_00_hpp

#include "../../Output.hpp"

class S50100 : public Output {
public:

	S50100() : Output(50100,	// Output ID
		false,	// Is tree end ?
		502, 	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"À l'extérieur de la salle."
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_501_00_hpp */
