//
//  O-140.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_140_hpp
#define O_140_hpp

#include "../../Output.hpp"

class O140: public Output {
public:

    O140(): Output(140,	            // Output ID
        false,	                    // Is tree end ?
        151,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "There are 2630 individuals in the room.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_140_hpp */
