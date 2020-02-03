//
//  O-22.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_22_hpp
#define O_22_hpp

#include "../../Output.hpp"

class O22: public Output {
public:

    O22(): Output(22,	            // Output ID
        true,	                    // Is tree end ?
        -1,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "I just keep learning from them.",
            "I learn a lot from our observations of them.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_22_hpp */
