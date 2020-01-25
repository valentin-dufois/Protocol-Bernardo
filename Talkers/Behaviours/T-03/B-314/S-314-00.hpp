//
//  S-314-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_314_00_hpp
#define S_314_00_hpp

#include "../../Output.hpp"

class S31400: public Output {
public:

	S31400(): Output(31400,	// Output ID
					 false,	// Is tree end ?
					 315,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Elles ne se connaissent peut-être pas."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_314_00_hpp */
