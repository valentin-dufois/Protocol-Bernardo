//
//  O-72.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_72_hpp
#define O_72_hpp

#include "../../Output.hpp"

class O72: public Output {
public:

    O72(): Output(72,	            // Output ID
        false,	                    // Is tree end ?
        93,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "No one has moved.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: Aucun mouvement brusque n'est détecté.
        */

        return true;
    }
};

#endif /* O_72_hpp */
