//
//  O-207.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_207_hpp
#define O_207_hpp

#include "../../Output.hpp"

class O207: public Output {
public:

    O207(): Output(207,	            // Output ID
        false,	                    // Is tree end ?
        202,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Maybe they are just strangers to each other.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_207_hpp */
