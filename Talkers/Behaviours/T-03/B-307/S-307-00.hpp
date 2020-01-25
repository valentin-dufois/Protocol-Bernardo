//
//  S-307-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_307_00_hpp
#define S_307_00_hpp

#include "../../Output.hpp"

class S30700: public Output {
public:

	S30700(): Output(30700,	// Output ID
					 false,	// Is tree end ?
					 308,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Elles sont toujours proches. Je me demande ce qu'elles peuvent bien faire."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return std::get<bool>(behaviourState["STILL_CLOSE"]);
	};
};

#endif /* S_307_00_hpp */
