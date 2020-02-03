//
//  O-34.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_34_hpp
#define O_34_hpp

#include "../../Output.hpp"

class O34: public Output {
public:

    O34(): Output(34,	            // Output ID
        false,	                    // Is tree end ?
        56,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "We could just ask. Assuming that they can read our discussion, which remains to prove.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_34_hpp */
