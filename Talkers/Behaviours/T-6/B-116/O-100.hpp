//
//  O-100.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_100_hpp
#define O_100_hpp

#include "../../Output.hpp"

class O100: public Output {
public:

    O100(): Output(100,	            // Output ID
        false,	                    // Is tree end ?
        117,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "I wonder about the frustration that this tireless return to our starting point can generate.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_100_hpp */
