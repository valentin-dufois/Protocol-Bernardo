//
//  S-802-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_802_00_hpp
#define S_802_00_hpp

#include "../../Output.hpp"

class S80200 : public Output {
public:

	S80200() : Output(80200,	// Output ID
		false,	// Is tree end ?
		803,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Elles y entrent peut-être par hasard."
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_802_00_hpp */
