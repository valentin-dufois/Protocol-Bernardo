//
//  O-183.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_183_hpp
#define O_183_hpp

#include "../../Output.hpp"

class O183: public Output {
public:

    O183(): Output(183,	            // Output ID
        false,	                    // Is tree end ?
        183,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "This might be the reason we work together as one.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_183_hpp */
