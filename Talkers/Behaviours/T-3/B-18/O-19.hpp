//
//  O-19.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_19_hpp
#define O_19_hpp

#include "../../Output.hpp"

class O19: public Output {
public:

    O19(): Output(19,	            // Output ID
        false,	                    // Is tree end ?
        82,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "There is someone moving.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 1/3 chance
        */

        return std::get<int>(behaviourState["RAND"]) < 66;
    }
};

#endif /* O_19_hpp */
