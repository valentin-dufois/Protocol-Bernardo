//
//  O-20.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_20_hpp
#define O_20_hpp

#include "../../Output.hpp"

class O20: public Output {
public:

    O20(): Output(20,	            // Output ID
        false,	                    // Is tree end ?
        21,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Not really. Look at us, we are working together to better understand what we observe.",
            "Not really. Look at us, we are working together to better comprehend our observervations.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_20_hpp */
