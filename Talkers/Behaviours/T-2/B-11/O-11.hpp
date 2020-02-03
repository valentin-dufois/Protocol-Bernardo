//
//  O-11.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_11_hpp
#define O_11_hpp

#include "../../Output.hpp"

class O11: public Output {
public:

    O11(): Output(11,	            // Output ID
        false,	                    // Is tree end ?
        17,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "See how they gather. They are social beings. They appreciate physical and mental proximity.",
            "Often, they appreciate being close to each other.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: CLOSE_ENCOUNTERS = true
        */

        return true;
    }
};

#endif /* O_11_hpp */
