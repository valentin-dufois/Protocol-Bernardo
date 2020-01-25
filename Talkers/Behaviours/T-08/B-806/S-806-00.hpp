//
//  S-806-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_806_00_hpp
#define S_806_00_hpp

#include "../../Output.hpp"

class S80600 : public Output {
public:

	S80600() : Output(80600,	// Output ID
		false,	// Is tree end ?
		807,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Si elles y ont été conviées, c'est que cet endroit présente un intérêt pour elles."
					 }) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_806_00_hpp */
