//
//  S-210-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_210_00_hpp
#define S_210_00_hpp

#include "../../Output.hpp"

class S21000: public Output {
public:

	S21000(): Output(21000,	// Output ID
					 false,	// Is tree end ?
					 211,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Il y a eu un mouvement brusque dans la salle."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_210_00_hpp */
