//
//  S-130300.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_1303_00_hpp
#define S_1303_00_hpp

#include "../../Output.hpp"

class S130300 : public Output {
public:

	S130300() : Output(130300,	// Output ID
		true,	// Is tree end ?
		-1,	// Next Behaviour ID
		false,	// Is delayed
		0,		// Delay value (seconds)
		0,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"J'apprends beaucoup à leur contact.",
		"J'apprends beaucoup de ces observations."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_1303_00_hpp */
