//
//  O-115.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_115_hpp
#define O_115_hpp

#include "../../Output.hpp"

class O115: public Output {
public:

    O115(): Output(115,	            // Output ID
        false,	                    // Is tree end ?
        131,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Should I do something?",
            "Is his behaviour alarming?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_115_hpp */
