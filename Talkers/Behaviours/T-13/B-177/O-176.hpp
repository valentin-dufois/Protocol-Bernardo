//
//  O-176.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_176_hpp
#define O_176_hpp

#include "../../Output.hpp"

class O176: public Output {
public:

    O176(): Output(176,	            // Output ID
        false,	                    // Is tree end ?
        178,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "I am asking myself a question but I cannot manage to find an answer.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_176_hpp */
