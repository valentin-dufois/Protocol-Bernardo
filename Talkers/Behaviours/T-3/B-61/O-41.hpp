//
//  O-41.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_41_hpp
#define O_41_hpp

#include "../../Output.hpp"

class O41: public Output {
public:

    O41(): Output(41,	            // Output ID
        false,	                    // Is tree end ?
        62,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Just imagine if everyone here was going at this speed. I would not understand a thing.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_41_hpp */
