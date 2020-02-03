//
//  O-96.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef O_96_hpp
#define O_96_hpp

#include "../../Output.hpp"

class O96: public Output {
public:

    O96(): Output(96,	            // Output ID
        false,	                    // Is tree end ?
        114,	                        // Next Behaviour ID
        DELAY_DEFAULT,	            // Is delayed
        DELAY_VALUE_DEFAULT,		// Delay value (seconds)
        DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
        {		                    // Output values
        },
        {		                    // Captions
            "I understand.",
        }) {}

    virtual bool isConditionValid(State &behaviourState) override {
        /*
        Condition: 50%
        */

        return std::get<int>(behaviourState["RAND"]) < 5;
    }
};

#endif /* O_96_hpp */
