//
//  O-189.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_189_hpp
#define O_189_hpp

#include "../../Output.hpp"

class O189: public Output {
public:

    O189(): Output(189,	            // Output ID
        false,	                    // Is tree end ?
        188,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "I have no idea. Maybe they just simply crossed each other.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_189_hpp */
