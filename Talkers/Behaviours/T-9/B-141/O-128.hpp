//
//  O-128.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_128_hpp
#define O_128_hpp

#include "../../Output.hpp"

class O128: public Output {
public:

    O128(): Output(128,	            // Output ID
        false,	                    // Is tree end ?
        142,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "It is a bit few.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: Le nombre total de personnes < 10
        */

        return std::get<int>(behaviourState["TOTAL_BODIES_COUNT"]) < 10;
    }
};

#endif /* O_128_hpp */
