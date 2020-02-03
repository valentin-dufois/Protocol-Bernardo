//
//  O-162.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_162_hpp
#define O_162_hpp

#include "../../Output.hpp"

class O162: public Output {
public:

    O162(): Output(162,	            // Output ID
        false,	                    // Is tree end ?
        167,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "The data we are analyzing does not allow us to give any certainty on what is happening outside this room.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_162_hpp */
