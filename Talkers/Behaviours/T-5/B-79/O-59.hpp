//
//  O-59.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_59_hpp
#define O_59_hpp

#include "../../Output.hpp"

class O59: public Output {
public:

    O59(): Output(59,	            // Output ID
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

#endif /* O_59_hpp */
