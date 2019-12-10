//
//  S-507-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_507_00_hpp
#define S_507_00_hpp

#include "../../Output.hpp"

class S50700 : public Output {
public:

	S50700() : Output(50700,	// Output ID
		false,	// Is tree end ?
		508, 	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Les données que nous analysons ne nous permettent pas d'émettre de certitude quant à ce qui se déroule à l'extérieur de cette salle."
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_507_00_hpp */
