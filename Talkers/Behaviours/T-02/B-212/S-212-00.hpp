//
//  S-212-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_212_00_hpp
#define S_212_00_hpp

#include "../../Output.hpp"

class S21200: public Output {
public:

	S21200(): Output(21200,	// Output ID
					 false,	// Is tree end ?
					 213,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Oui, peut-être.\nComment en avoir la certitude ?"
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_212_00_hpp */
