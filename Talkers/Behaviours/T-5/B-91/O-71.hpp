//
//  O-71.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_71_hpp
#define O_71_hpp

#include "../../Output.hpp"

class O71: public Output {
public:

    O71(): Output(71,	            // Output ID
        false,	                    // Is tree end ?
        92,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "I have read a significant move from {MOVING_BODIES_COUNT} person.people.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: Au moins un mouvement brusque est détecté.
        */

        _state["MOVING_BODIES_COUNT"] = std::to_string(std::get<int>(behaviourState["MOVING_BODIES_COUNT_INT"]));

		return std::get<int>(behaviourState["MOVING_BODIES_COUNT_INT"]) > 0;
    }
};

#endif /* O_71_hpp */
