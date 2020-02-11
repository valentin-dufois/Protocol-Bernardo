//
//  O-1.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_1_hpp
#define O_1_hpp

#include "../../Output.hpp"

class O1: public Output {
public:

    O1(): Output(1,	            // Output ID
        false,	                    // Is tree end ?
        3,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Although I detect {BODY_COUNT} person, I do not detect motion.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        _state["BODY_COUNT"] = std::to_string(std::get<int>(behaviourState["BODY_COUNT_INT"]));
		return std::get<int>(behaviourState["BODY_COUNT_INT"]) <= 1;
    }
};

#endif /* O_1_hpp */
