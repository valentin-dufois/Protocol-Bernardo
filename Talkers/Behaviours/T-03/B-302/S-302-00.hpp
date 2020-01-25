//
//  S-302-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_302_00_hpp
#define S_302_00_hpp

#include "../../Output.hpp"

class S30200: public Output {
public:

	S30200(): Output(30200,	// Output ID
					 false,	// Is tree end ?
					 303,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
					 {		// Output values
	},
					 {		// Captions
		"Je ne sais pas. Peut être qu'elle viennent simplement de se croiser."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_302_00_hpp */
