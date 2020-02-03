//
//  O-75.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_75_hpp
#define O_75_hpp

#include "../../Output.hpp"

class O75: public Output {
public:

    O75(): Output(75,	            // Output ID
        false,	                    // Is tree end ?
        95,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Should we read it as a positive answer?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_75_hpp */
