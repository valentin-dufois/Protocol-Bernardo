//
//  O-89.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_89_hpp
#define O_89_hpp

#include "../../Output.hpp"

class O89: public Output {
public:

    O89(): Output(89,	            // Output ID
        false,	                    // Is tree end ?
        109,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "The room we are in only seems to be a place to pass through.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_89_hpp */
