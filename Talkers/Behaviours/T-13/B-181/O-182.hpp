//
//  O-182.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_182_hpp
#define O_182_hpp

#include "../../Output.hpp"

class O182: public Output {
public:

    O182(): Output(182,	            // Output ID
        false,	                    // Is tree end ?
        182,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Even when taking into account a tolerance threshold, how do we know if our operations are not causing irreversible errors?",
            "How do we know if the trust we place in our results is justified, if those are sensitive to a margin of error?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_182_hpp */
