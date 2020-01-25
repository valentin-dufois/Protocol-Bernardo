//
//  S-207-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_207_00_hpp
#define S_207_00_hpp

#include "../../Output.hpp"

class S20700: public Output {
public:

	S20700(): Output(20700,	// Output ID
					 false,	// Is tree end ?
					 208,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Cette perspective attise tout de même ma curiosité."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_207_00_hpp */
