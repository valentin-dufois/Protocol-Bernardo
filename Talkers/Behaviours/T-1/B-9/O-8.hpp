//
//  O-8.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_8_hpp
#define O_8_hpp

#include "../../Output.hpp"

class O8: public Output {
public:

    O8(): Output(8,	            // Output ID
        false,	                    // Is tree end ?
        10,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Many questions to which I do not have answers.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_8_hpp */
