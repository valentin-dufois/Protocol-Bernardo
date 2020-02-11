//
//  O-9997.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_9997_hpp
#define O_9997_hpp

#include "../../Output.hpp"

class O9997: public Output {
public:

    O9997(): Output(9997,	            // Output ID
        false,	                    // Is tree end ?
        141,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
            "TOTAL_BODIES_COUNT",
        },
        {		                    // Captions
            "Until now, I have counted {TOTAL_BODIES_COUNT_STR} people in the entire room.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        _state["TOTAL_BODIES_COUNT"] = behaviourState["TOTAL_BODIES_COUNT_INT"];
		_state["TOTAL_BODIES_COUNT_STR"] = std::to_string(std::get<int>(behaviourState["TOTAL_BODIES_COUNT"]));
		return std::get<int>(behaviourState["TOTAL_BODIES_COUNT_INT"]) > 1;
    }
};

#endif /* O_9997_hpp */
