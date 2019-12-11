//
//  S-1301-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_1301_00_hpp
#define S_1301_00_hpp

#include "../../Output.hpp"

class S130100 : public Output {
public:

	S130100() : Output(130100,	// Output ID
		false,	// Is tree end ?
		1302,	// Next Behaviour ID
		false,	// Is delayed
		0,		// Delay value (seconds)
		0,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"C'est un comportement étrange.",
		"C'est un comportement inattendu."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_1301_00_hpp */
