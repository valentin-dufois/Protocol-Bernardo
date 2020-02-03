//
//  O-31.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_31_hpp
#define O_31_hpp

#include "../../Output.hpp"

class O31: public Output {
public:

    O31(): Output(31,	            // Output ID
        false,	                    // Is tree end ?
        52,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Do you think the individuals we observe are also observing us?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_31_hpp */
