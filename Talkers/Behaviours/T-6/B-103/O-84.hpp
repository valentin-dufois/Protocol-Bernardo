//
//  O-84.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_84_hpp
#define O_84_hpp

#include "../../Output.hpp"

class O84: public Output {
public:

    O84(): Output(84,	            // Output ID
        false,	                    // Is tree end ?
        104,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Or maybe they have been invited to come in.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_84_hpp */
