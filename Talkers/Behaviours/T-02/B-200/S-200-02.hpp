//
//  S-200-02.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_200_02_hpp
#define S_200_02_hpp

#include "../../Output.hpp"

class S20002 : public Output {
public:

	S20002() : Output(20002,	// Output ID
		true,	// Is tree end ?
		1200,	// Next Behaviour ID
		false,	// Is delayed
		0,		// Delay value (seconds)
		0,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Celui-ci est agité.",
		"Il y a quelqu'un qui remue beaucoup."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_200_02_hpp */
