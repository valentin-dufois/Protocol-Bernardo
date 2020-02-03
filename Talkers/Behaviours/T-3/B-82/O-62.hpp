//
//  O-62.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_62_hpp
#define O_62_hpp

#include "../../Output.hpp"

class O62: public Output {
public:

    O62(): Output(62,	            // Output ID
        false,	                    // Is tree end ?
        85,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Save it.",
            "Store this in the database.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_62_hpp */
