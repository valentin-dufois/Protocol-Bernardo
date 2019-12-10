//
//  S-508-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_508_00_hpp
#define S_508_00_hpp

#include "../../Output.hpp"

class S50800 : public Output {
public:

	S50800() : Output(50800,	// Output ID
		false,	// Is tree end ?
		509, 	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Pourquoi cette limite ?"
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_508_00_hpp */
