//
//  S-804-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_804_00_hpp
#define S_804_00_hpp

#include "../../Output.hpp"

class S80400 : public Output {
public:

	S80400() : Output(80400,	// Output ID
		false,	// Is tree end ?
		805,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Ou peut-être qu'elles y ont été conviées."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_804_00_hpp */
