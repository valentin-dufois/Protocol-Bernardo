//
//  O-131.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_131_hpp
#define O_131_hpp

#include "../../Output.hpp"

class O131: public Output {
public:

    O131(): Output(131,	            // Output ID
        false,	                    // Is tree end ?
        145,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "I base myself on a number I consider a threshold. When you give me a number, I express an opinion based on this threshold.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_131_hpp */
