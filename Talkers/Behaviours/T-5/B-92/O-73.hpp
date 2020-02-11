//
//  O-73.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_73_hpp
#define O_73_hpp

#include "../../Output.hpp"

class O73: public Output {
public:

    O73(): Output(73,	            // Output ID
        false,	                    // Is tree end ?
        94,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Interesting.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_73_hpp */
