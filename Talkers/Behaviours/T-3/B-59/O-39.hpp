//
//  O-39.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_39_hpp
#define O_39_hpp

#include "../../Output.hpp"

class O39: public Output {
public:

    O39(): Output(39,	            // Output ID
        false,	                    // Is tree end ?
        61,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
            "SUDN_MOVE_SPEED_TIMES_AVERAGE",
        },
        {		                    // Captions
            "It is {SUDN_MOVE_SPEED_TIMES_AVERAGE} times the average speed of the people currently here.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        _state["SUDN_MOVE_SPEED_TIMES_AVERAGE"] = std::to_string(std::get<double>(behaviourState["SUDDEN_MOVE_SPEED_TIMES_FROM_AVERAGE_DOUBLE"]));
		return true;
    }
};

#endif /* O_39_hpp */
