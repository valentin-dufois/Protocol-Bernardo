//
//  O-2.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_2_hpp
#define O_2_hpp

#include "../../Output.hpp"

class O2: public Output {
public:

    O2(): Output(2,	            // Output ID
        false,	                    // Is tree end ?
        4,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Those people have stabilized their position simultaneously. Interesting.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_2_hpp */
