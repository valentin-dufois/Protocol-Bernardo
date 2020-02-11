//
//  O-50.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_50_hpp
#define O_50_hpp

#include "../../Output.hpp"

class O50: public Output {
public:

    O50(): Output(50,	            // Output ID
        false,	                    // Is tree end ?
        81,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "It leads us to believe that they are observing us.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_50_hpp */
