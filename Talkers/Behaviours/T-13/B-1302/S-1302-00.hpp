//
//  S-1302-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_1302_00_hpp
#define S_1302_00_hpp

#include "../../Output.hpp"

class S130200 : public Output {
public:

	S130200() : Output(130200,	// Output ID
		true,	// Is tree end ?
		1303,	// Next Behaviour ID
		false,	// Is delayed
		0,		// Delay value (seconds)
		0,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Pas vraiment. Nous travaillons à deux pour mieux comprendre ce que nous observons.",
		"Pas vraiment. Nous travaillons à deux pour mieux appréhender nos observations."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_1302_00_hpp */
