//
//  S-215-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_216_00_hpp
#define S_216_00_hpp

#include "../../Output.hpp"

class S21600: public Output {
public:

	S21600(): Output(21600,	// Output ID
					 false,	// Is tree end ?
					 217,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Aucune certitude donc. On tourne en rond."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_216_00_hpp */
