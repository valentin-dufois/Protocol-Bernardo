//
//  S-1300-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_1300_00_hpp
#define S_1300_00_hpp

#include "../../Output.hpp"

class S130000 : public Output {
public:

	S130000() : Output(130000,	// Output ID
		false,	// Is tree end ?
		1301,	// Next Behaviour ID
		false,	// Is delayed
		0,		// Delay value (seconds)
		0,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Remarque comme ils se rassemblent. Ce sont des êtres sociaux. Ils apprécient la proximité physique et mentale.",
		"Ils apprécient souvent d'être collés les uns aux autres."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_1300_00_hpp */
