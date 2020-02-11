//
//  O-9998.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_9998_hpp
#define O_9998_hpp

#include "../../Output.hpp"

class O9998: public Output {
public:

    O9998(): Output(9998,	            // Output ID
        false,	                    // Is tree end ?
        92,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "I have read a significant move from {MOVING_BODIES_COUNT} people.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: Au moins un mouvement brusque est détecté.
        */

        _state["MOVING_BODIES_COUNT"] = std::to_string(std::get<int>(behaviourState["MOVING_BODIES_COUNT_INT"]));

		return std::get<int>(behaviourState["MOVING_BODIES_COUNT_INT"]) > 1;
    }
};

#endif /* O_9998_hpp */
