//
//  O-26.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_26_hpp
#define O_26_hpp

#include "../../Output.hpp"

class O26: public Output {
public:

    O26(): Output(26,	            // Output ID
        false,	                    // Is tree end ?
        47,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Oh! Someone new just entered. Did you see it too?",
            "I sensed a new move. Do you have identical data?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: NEW_DETEC = true
        */

        return true;
    }
};

#endif /* O_26_hpp */
