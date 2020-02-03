//
//  O-181.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_181_hpp
#define O_181_hpp

#include "../../Output.hpp"

class O181: public Output {
public:

    O181(): Output(181,	            // Output ID
        false,	                    // Is tree end ?
        181,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Certainly. What is your question?",
            "Surely. What was your question?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_181_hpp */
