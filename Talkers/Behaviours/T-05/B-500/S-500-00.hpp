//
//  S-500-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_500_00_hpp
#define S_500_00_hpp

#include "../../Output.hpp"

class S50000 : public Output {
public:

	S50000() : Output(50000,	// Output ID
		false,	// Is tree end ?
		501,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
					 {		// Captions
		"Où sont les personnes lorqu'elles ne sont pas dans la salle ?"
					 }) {}

	virtual bool isConditionValid(const State &behaviourState) override {
		return true;
	};
};

#endif /* S_500_00_hpp */
