//
//  B-69.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2020-02-03.
//

#ifndef B_69_hpp
#define B_69_hpp

#ifdef B69
#undef B69
#endif

#include "../../Behaviour.hpp"

class B69: public Behaviour {
public:
    B69(): Behaviour(69,	// ID
        3,		            // Tree ID
        1,	                // Is tree start ?
        0,	                // Force start ?
        {		            // Expected inputs
        },
        {		            // Expected outputs
            49,
    }) {}

    virtual bool execute(Machine * machine) override {
        /*
        Action: 
        */

        return true;
    }
};


#endif /* B_69_hpp */
