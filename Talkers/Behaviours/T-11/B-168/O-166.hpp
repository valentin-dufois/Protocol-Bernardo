//
//  O-166.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_166_hpp
#define O_166_hpp

#include "../../Output.hpp"

class O166: public Output {
public:

    O166(): Output(166,	            // Output ID
        false,	                    // Is tree end ?
        170,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "I do not know. Our purpose seems to be defined only within this room.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_166_hpp */
