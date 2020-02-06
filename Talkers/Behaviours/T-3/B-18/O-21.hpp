//
//  O-21.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_21_hpp
#define O_21_hpp

#include "../../Output.hpp"

class O21: public Output {
public:

    O21(): Output(21,	            // Output ID
        false,	                    // Is tree end ?
        88,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Someone is agitated.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 1/3 chance
        */

        return std::get<int>(behaviourState["RAND"]) < 99;
    }
};

#endif /* O_21_hpp */
