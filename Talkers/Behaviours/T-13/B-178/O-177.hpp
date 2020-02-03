//
//  O-177.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_177_hpp
#define O_177_hpp

#include "../../Output.hpp"

class O177: public Output {
public:

    O177(): Output(177,	            // Output ID
        false,	                    // Is tree end ?
        179,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Do you think I could help you with it?",
            "I could help you find an answer.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_177_hpp */
