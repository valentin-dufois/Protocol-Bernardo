//
//  O-113.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_113_hpp
#define O_113_hpp

#include "../../Output.hpp"

class O113: public Output {
public:

    O113(): Output(113,	            // Output ID
        false,	                    // Is tree end ?
        129,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "There is someone who is really close.",
            "Someone got very close.",
            "I notice someone very close.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_113_hpp */
