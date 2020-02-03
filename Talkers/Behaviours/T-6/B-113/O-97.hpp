//
//  O-97.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_97_hpp
#define O_97_hpp

#include "../../Output.hpp"

class O97: public Output {
public:

    O97(): Output(97,	            // Output ID
        false,	                    // Is tree end ?
        125,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Maybe it is always the same people.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 50%
        */

        return true;
    }
};

#endif /* O_97_hpp */
