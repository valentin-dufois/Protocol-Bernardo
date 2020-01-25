//
//  S-300-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_300_00_hpp
#define S_300_00_hpp

#include "../../Output.hpp"

class S30000: public Output {
public:

	S30000(): Output(30000,	// Output ID
					 false,	// Is tree end ?
					 301,	// Next Behaviour ID
					 false,	// Is delayed
					 0,		// Delay value (seconds)
					 0,		// Delay variance (seconds)
					 {		// Output values
		"BODY_ID_A",
		"BODY_ID_B"
	},
					 {		// Captions
		"As-tu détecté ça ?."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		_state["BODY_ID_A"] = behaviourState["BODY_ID_A"];
		_state["BODY_ID_B"] = behaviourState["BODY_ID_B"];
		return true;
	};
};

#endif /* S_300_00_hpp */
