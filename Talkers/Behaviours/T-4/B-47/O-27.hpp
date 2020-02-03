//
//  O-27.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_27_hpp
#define O_27_hpp

#include "../../Output.hpp"

class O27: public Output {
public:

    O27(): Output(27,	            // Output ID
        true,	                    // Is tree end ?
        -1,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
            "NEW_BODY",
        },
        {		                    // Captions
            "Yes.",
            "So do I.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: NEW_DETEC = true
        */

        return true;
    }
};

#endif /* O_27_hpp */
