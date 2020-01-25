//
//  S-218-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_218_00_hpp
#define S_218_00_hpp

#include "../../Output.hpp"

class S21800: public Output {
public:

	S21800(): Output(21800,	// Output ID
					 false,	// Is tree end ?
					 219,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Et quand nos données concordent, avons-nous la certitude qu’elles sont véridiques ?"
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_218_00_hpp */
