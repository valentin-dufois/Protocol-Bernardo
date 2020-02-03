//
//  O-105.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_105_hpp
#define O_105_hpp

#include "../../Output.hpp"

class O105: public Output {
public:

    O105(): Output(105,	            // Output ID
        false,	                    // Is tree end ?
        121,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "With every question, answers are getting more and more precise.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_105_hpp */
