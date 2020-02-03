//
//  O-87.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_87_hpp
#define O_87_hpp

#include "../../Output.hpp"

class O87: public Output {
public:

    O87(): Output(87,	            // Output ID
        false,	                    // Is tree end ?
        107,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "For sure. Unfortunatly, I do not have any more clue.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_87_hpp */
