//
//  O-55.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_55_hpp
#define O_55_hpp

#include "../../Output.hpp"

class O55: public Output {
public:

    O55(): Output(55,	            // Output ID
        false,	                    // Is tree end ?
        87,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "No, nothing noticeable.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

            return true;
            };
};

#endif /* O_55_hpp */
