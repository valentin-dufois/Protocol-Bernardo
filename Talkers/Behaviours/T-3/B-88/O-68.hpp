//
//  O-68.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_68_hpp
#define O_68_hpp

#include "../../Output.hpp"

class O68: public Output {
public:

    O68(): Output(68,	            // Output ID
        false,	                    // Is tree end ?
        89,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Surely a wish to have fun with the sensors.",
            "Sensors always lead them to that kind of behaviour.",
            "When they notice the sensors, they always react like this.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_68_hpp */
