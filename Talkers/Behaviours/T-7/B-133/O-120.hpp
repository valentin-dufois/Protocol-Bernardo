//
//  O-120.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_120_hpp
#define O_120_hpp

#include "../../Output.hpp"

class O120: public Output {
public:

    O120(): Output(120,	            // Output ID
        false,	                    // Is tree end ?
        135,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "What are you up to?",
            "What is wrong?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_120_hpp */
