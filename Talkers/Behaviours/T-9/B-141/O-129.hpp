//
//  O-129.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_129_hpp
#define O_129_hpp

#include "../../Output.hpp"

class O129: public Output {
public:

    O129(): Output(129,	            // Output ID
        false,	                    // Is tree end ?
        156,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Still.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: Le nombre total de personnes >= 10
        */

        return std::get<int>(behaviourState["TOTAL_BODIES_COUNT"]) >= 10;
    }
};

#endif /* O_129_hpp */
