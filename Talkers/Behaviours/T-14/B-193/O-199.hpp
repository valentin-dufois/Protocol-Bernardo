//
//  O-199.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_199_hpp
#define O_199_hpp

#include "../../Output.hpp"

class O199: public Output {
public:

    O199(): Output(199,	            // Output ID
        false,	                    // Is tree end ?
        200,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "They just split.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: Les deux personnes ne sont plus proches.
        */

        return !std::get<bool>(behaviourState["STILL_CLOSE"]);
    }
};

#endif /* O_199_hpp */
