//
//  O-40.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_40_hpp
#define O_40_hpp

#include "../../Output.hpp"

class O40: public Output {
public:

    O40(): Output(40,	            // Output ID
        false,	                    // Is tree end ?
        70,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
            "MOVING_BODIES_COUNT",
        },
        {		                    // Captions
            "A few beings gave a sign by ostensibly moving.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: Au moins un mouvement brusque est détecté.
        */

        return std::get<int>(behaviourState["MOVING_BODIES_COUNT_INT"]) > 0;
    }
};

#endif /* O_40_hpp */
