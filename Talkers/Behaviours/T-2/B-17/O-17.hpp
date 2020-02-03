//
//  O-17.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_17_hpp
#define O_17_hpp

#include "../../Output.hpp"

class O17: public Output {
public:

    O17(): Output(17,	            // Output ID
        false,	                    // Is tree end ?
        20,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "It is an unusual behaviour.",
            "It is an unexpected behaviour.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_17_hpp */
