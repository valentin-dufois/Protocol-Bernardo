//
//  O-136.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_136_hpp
#define O_136_hpp

#include "../../Output.hpp"

class O136: public Output {
public:

    O136(): Output(136,	            // Output ID
        false,	                    // Is tree end ?
        148,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "Interesting. If I give you another number, will you go through the same process?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_136_hpp */
