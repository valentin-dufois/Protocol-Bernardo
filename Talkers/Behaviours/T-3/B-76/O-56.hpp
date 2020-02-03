//
//  O-56.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_56_hpp
#define O_56_hpp

#include "../../Output.hpp"

class O56: public Output {
public:

    O56(): Output(56,	            // Output ID
        false,	                    // Is tree end ?
        77,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "When our data match, how do we have absolute certainty they are truthful?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_56_hpp */
