//
//  O-45.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_45_hpp
#define O_45_hpp

#include "../../Output.hpp"

class O45: public Output {
public:

    O45(): Output(45,	            // Output ID
        false,	                    // Is tree end ?
        87,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "No. Nothing noticeable.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: Aucun mouvement brusque n'est détecté.
        */

        return true;
    }
};

#endif /* O_45_hpp */
