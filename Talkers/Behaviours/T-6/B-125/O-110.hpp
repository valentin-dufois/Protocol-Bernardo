//
//  O-110.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_110_hpp
#define O_110_hpp

#include "../../Output.hpp"

class O110: public Output {
public:

    O110(): Output(110,	            // Output ID
        false,	                    // Is tree end ?
        126,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "I have noticed some similarities in their behaviour. So it is a possibility.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_110_hpp */
