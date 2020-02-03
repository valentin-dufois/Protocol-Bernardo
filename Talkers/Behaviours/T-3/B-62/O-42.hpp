//
//  O-42.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_42_hpp
#define O_42_hpp

#include "../../Output.hpp"

class O42: public Output {
public:

    O42(): Output(42,	            // Output ID
        false,	                    // Is tree end ?
        63,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "This possibility is stiring my curiosity.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_42_hpp */
