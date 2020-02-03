//
//  O-114.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_114_hpp
#define O_114_hpp

#include "../../Output.hpp"

class O114: public Output {
public:

    O114(): Output(114,	            // Output ID
        false,	                    // Is tree end ?
        130,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "is that so?",
            "And so what?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_114_hpp */
