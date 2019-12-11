//
//  S-1201-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-11.
//

#ifndef S_1201_00_hpp
#define S_1201_00_hpp

#include "../../Output.hpp"

class S120100 : public Output {
public:

	S120100() : Output(120100,	// Output ID
		true,	// Is tree end ?
		1202,	// Next Behaviour ID
		false,	// Is delayed
		0,		// Delay value (seconds)
		0,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Sûrement une envie de s'amuser avec les capteurs.",
		"Les capteurs leur font toujours cet effet.",
		"Quand ils remarquent les capteurs, ils font toujours ce genre de choses."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_1201_00_hpp */
