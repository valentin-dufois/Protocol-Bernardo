//
//  O-179.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_179_hpp
#define O_179_hpp

#include "../../Output.hpp"

class O179: public Output {
public:

    O179(): Output(179,	            // Output ID
        false,	                    // Is tree end ?
        180,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "It might help. Together, we should be more effective.",
            "There is a high probability that we are more effective together.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_179_hpp */
