//
//  O-48.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_48_hpp
#define O_48_hpp

#include "../../Output.hpp"

class O48: public Output {
public:

    O48(): Output(48,	            // Output ID
        false,	                    // Is tree end ?
        69,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Sure, it could be. How can we be sure?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_48_hpp */
