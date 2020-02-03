//
//  O-197.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_197_hpp
#define O_197_hpp

#include "../../Output.hpp"

class O197: public Output {
public:

    O197(): Output(197,	            // Output ID
        false,	                    // Is tree end ?
        195,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "They are still quite close from each other. I am wondering what they are up to.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: Les deux personnes sont toujours proches.
        */

        return std::get<bool>(behaviourState["STILL_CLOSE"]);
    }
};

#endif /* O_197_hpp */
