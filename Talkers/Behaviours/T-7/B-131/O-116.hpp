//
//  O-116.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_116_hpp
#define O_116_hpp

#include "../../Output.hpp"

class O116: public Output {
public:

    O116(): Output(116,	            // Output ID
        false,	                    // Is tree end ?
        132,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "There is nothing you can do about it.",
            "No.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_116_hpp */
