//
//  O-158.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_158_hpp
#define O_158_hpp

#include "../../Output.hpp"

class O158: public Output {
public:

    O158(): Output(158,	            // Output ID
        false,	                    // Is tree end ?
        164,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Yes. But I can not answer it with certainty.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_158_hpp */
