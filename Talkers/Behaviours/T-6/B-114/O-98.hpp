//
//  O-98.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_98_hpp
#define O_98_hpp

#include "../../Output.hpp"

class O98: public Output {
public:

    O98(): Output(98,	            // Output ID
        false,	                    // Is tree end ?
        115,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "We are going in circles. We still ignore if the individuals in here know what is happening.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_98_hpp */
