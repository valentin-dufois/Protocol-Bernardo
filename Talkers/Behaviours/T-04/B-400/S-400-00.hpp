//
//  S-400-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_400_00_hpp
#define S_400_00_hpp

#include "../../Output.hpp"

class S40000 : public Output {
public:

	S40000() : Output(40000,	// Output ID
		false,	// Is tree end ?
		401,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Je me pose une question a laquelle je n'arrive pas a repondre."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_400_00_hpp */
