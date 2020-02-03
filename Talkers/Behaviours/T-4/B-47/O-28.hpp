//
//  O-28.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_28_hpp
#define O_28_hpp

#include "../../Output.hpp"

class O28: public Output {
public:

    O28(): Output(28,	            // Output ID
        true,	                    // Is tree end ?
        -1,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
            "NEW_BODY",
        },
        {		                    // Captions
            "No.",
            "Not yet.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: NEW_DETEC = false
        */

        return true;
    }
};

#endif /* O_28_hpp */
