//
//  O-47.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_47_hpp
#define O_47_hpp

#include "../../Output.hpp"

class O47: public Output {
public:

    O47(): Output(47,	            // Output ID
        false,	                    // Is tree end ?
        68,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Nothing on my side. It could be a false data.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_47_hpp */
