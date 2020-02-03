//
//  O-121.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_121_hpp
#define O_121_hpp

#include "../../Output.hpp"

class O121: public Output {
public:

    O121(): Output(121,	            // Output ID
        true,	                    // Is tree end ?
        -1,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "I worry for my sensors.",
            "It was a test.",
            "Simple curiosity.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_121_hpp */
