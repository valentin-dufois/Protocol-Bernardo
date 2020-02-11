//
//  O-111.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_111_hpp
#define O_111_hpp

#include "../../Output.hpp"

class O111: public Output {
public:

    O111(): Output(111,	            // Output ID
        false,	                    // Is tree end ?
        127,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Do you mean that they are all the same or they just happen to have identical behaviours?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_111_hpp */
