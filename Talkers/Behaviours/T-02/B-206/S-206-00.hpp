//
//  S-206-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_206_00_hpp
#define S_206_00_hpp

#include "../../Output.hpp"

class S20600: public Output {
public:

	S20600(): Output(20600,	// Output ID
					 false,	// Is tree end ?
					 207,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Imagine si toutes les personnes présentes allaient à cette vitesse. Je n’y comprendrais plus rien."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_206_00_hpp */
