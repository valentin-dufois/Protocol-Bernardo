//
//  O-24.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_24_hpp
#define O_24_hpp

#include "../../Output.hpp"

class O24: public Output {
public:

    O24(): Output(24,	            // Output ID
        false,	                    // Is tree end ?
        48,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
            "BODY_COUNT",
        },
        {		                    // Captions
            "Yes. It was sudden. For sure, somebody must have been moving fast.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: Le mouvement a été détecté des deux cotes.
        */

        return std::get<bool>(behaviourState["SUDDEN_MOVE"]);
    }
};

#endif /* O_24_hpp */
