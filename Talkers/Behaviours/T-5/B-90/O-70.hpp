//
//  O-70.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_70_hpp
#define O_70_hpp

#include "../../Output.hpp"

class O70: public Output {
public:

    O70(): Output(70,	            // Output ID
        false,	                    // Is tree end ?
        91,	                        // Next Behaviour ID
        1,	            // Is delayed
        10,		// Delay value (seconds)
        2,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "So?",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 
        */

        return true;
    }
};

#endif /* O_70_hpp */
