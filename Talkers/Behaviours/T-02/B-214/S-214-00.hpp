//
//  S-214-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_214_00_hpp
#define S_214_00_hpp

#include "../../Output.hpp"

class S21400: public Output {
public:

	S21400(): Output(21400,	// Output ID
					 false,	// Is tree end ?
					 215,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Donc l’erreur pourrait ne pas venir de moi."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_214_00_hpp */
