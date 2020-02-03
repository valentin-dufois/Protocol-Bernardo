//
//  O-86.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_86_hpp
#define O_86_hpp

#include "../../Output.hpp"

class O86: public Output {
public:

    O86(): Output(86,	            // Output ID
        false,	                    // Is tree end ?
        106,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "If they were invited, it means that this room is of a certain interest.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_86_hpp */
