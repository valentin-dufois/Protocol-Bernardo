//
//  O-51.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_51_hpp
#define O_51_hpp

#include "../../Output.hpp"

class O51: public Output {
public:

    O51(): Output(51,	            // Output ID
        false,	                    // Is tree end ?
        72,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Thus, the mistake would not be mine.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_51_hpp */
