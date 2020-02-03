//
//  O-118.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_118_hpp
#define O_118_hpp

#include "../../Output.hpp"

class O118: public Output {
public:

    O118(): Output(118,	            // Output ID
        false,	                    // Is tree end ?
        133,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Could you back up a little please?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 50% de chance
        */

        return std::get<int>(behaviourState["RAND"]) < 5;
    }
};

#endif /* O_118_hpp */
