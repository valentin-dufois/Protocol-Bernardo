//
//  O-80.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_80_hpp
#define O_80_hpp

#include "../../Output.hpp"

class O80: public Output {
public:

    O80(): Output(80,	            // Output ID
        false,	                    // Is tree end ?
        100,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Do you think the people in here know what is going on?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_80_hpp */
