//
//  O-119.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_119_hpp
#define O_119_hpp

#include "../../Output.hpp"

class O119: public Output {
public:

    O119(): Output(119,	            // Output ID
        true,	                    // Is tree end ?
        -1,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Alright.",
            "So be it.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 50% de chance
        */

        return std::get<int>(behaviourState["RAND"]) < 10;
    }
};

#endif /* O_119_hpp */
