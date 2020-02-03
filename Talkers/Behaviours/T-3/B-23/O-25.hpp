//
//  O-25.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_25_hpp
#define O_25_hpp

#include "../../Output.hpp"

class O25: public Output {
public:

    O25(): Output(25,	            // Output ID
        false,	                    // Is tree end ?
        65,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "No, what are you talking about?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: Le mouvement n'a pas été détecté des deux côtés.
        */

        return !std::get<bool>(behaviourState["SUDDEN_MOVE"]);
    }
};

#endif /* O_25_hpp */
