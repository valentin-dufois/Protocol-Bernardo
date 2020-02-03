//
//  O-67.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_67_hpp
#define O_67_hpp

#include "../../Output.hpp"

class O67: public Output {
public:

    O67(): Output(67,	            // Output ID
        false,	                    // Is tree end ?
        90,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "I will try.\nAre you watching us?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_67_hpp */
