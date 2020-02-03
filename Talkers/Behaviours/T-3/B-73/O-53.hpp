//
//  O-53.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_53_hpp
#define O_53_hpp

#include "../../Output.hpp"

class O53: public Output {
public:

    O53(): Output(53,	            // Output ID
        false,	                    // Is tree end ?
        75,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "No absolute certainty then. It seems we are going in circles.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_53_hpp */
