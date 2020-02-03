//
//  O-6.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_6_hpp
#define O_6_hpp

#include "../../Output.hpp"

class O6: public Output {
public:

    O6(): Output(6,	            // Output ID
        false,	                    // Is tree end ?
        8,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "You are asking a lot of questions.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_6_hpp */
