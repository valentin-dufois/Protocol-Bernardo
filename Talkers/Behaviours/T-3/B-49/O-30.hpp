//
//  O-30.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_30_hpp
#define O_30_hpp

#include "../../Output.hpp"

class O30: public Output {
public:

    O30(): Output(30,	            // Output ID
        false,	                    // Is tree end ?
        55,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
            "SUDDEN_MOVE_SPEED",
        },
        {		                    // Captions
            "Exactly at {SUDDEN_MOVE_SPEED_STR} m/s. According to my calculations.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition:
        */

		_state["SUDDEN_MOVE_SPEED_STR"] = std::to_string(std::get<double>(behaviourState["SUDDEN_MOVE_SPEED_DOUBLE"]));
		_state["SUDDEN_MOVE_SPEED"] = behaviourState["SUDDEN_MOVE_SPEED_DOUBLE"];
		return true;
    }
};

#endif /* O_30_hpp */
