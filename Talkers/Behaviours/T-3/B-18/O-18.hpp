//
//  O-18.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_18_hpp
#define O_18_hpp

#include "../../Output.hpp"

class O18: public Output {
public:

    O18(): Output(18,	            // Output ID
        false,	                    // Is tree end ?
        23,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
            "SUDDEN_MOVE_SPEED",
        },
        {		                    // Captions
            "Have you detected that?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 1/3 chance
        */

        _state["SUDDEN_MOVE_SPEED"] = behaviourState["SUDDEN_MOVE_SPEED_DOUBLE"];
		return std::get<int>(behaviourState["RAND"]) < 33;
    }
};

#endif /* O_18_hpp */
