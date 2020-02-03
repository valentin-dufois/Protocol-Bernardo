//
//  O-94.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_94_hpp
#define O_94_hpp

#include "../../Output.hpp"

class O94: public Output {
public:

    O94(): Output(94,	            // Output ID
        false,	                    // Is tree end ?
        113,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Yes. We detect people and then we do not. What I read from that is they are just coming and going.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_94_hpp */
