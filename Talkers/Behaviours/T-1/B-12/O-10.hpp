//
//  O-10.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_10_hpp
#define O_10_hpp

#include "../../Output.hpp"

class O10: public Output {
public:

    O10(): Output(10,	            // Output ID
        false,	                    // Is tree end ?
        13,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
            "QUESTIONS_RECEIVED_COUNT",
        },
        {		                    // Captions
            "Exactly {QUESTIONS_RECEIVED_COUNT}.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        _state["QUESTIONS_RECEIVED_COUNT"] = behaviourState["QUESTIONS_RECEIVED_COUNT"];

		return true;
    }
};

#endif /* O_10_hpp */
