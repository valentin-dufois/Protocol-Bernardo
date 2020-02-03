//
//  O-156.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_156_hpp
#define O_156_hpp

#include "../../Output.hpp"

class O156: public Output {
public:

    O156(): Output(156,	            // Output ID
        false,	                    // Is tree end ?
        162,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "It could not. I do not have more details than you.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_156_hpp */
