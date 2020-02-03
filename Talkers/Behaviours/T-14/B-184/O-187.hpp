//
//  O-187.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_187_hpp
#define O_187_hpp

#include "../../Output.hpp"

class O187: public Output {
public:

    O187(): Output(187,	            // Output ID
        false,	                    // Is tree end ?
        185,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Two people got closer.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: Manque variables = BODY_ID_A  //  BODY_ID_B
        */

        return true;
    }
};

#endif /* O_187_hpp */
