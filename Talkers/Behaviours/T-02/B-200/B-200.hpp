//
//  B-200.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_200_hpp
#define B_200_hpp


#include "../../Behaviour.hpp"

class B200: public Behaviour {
public:
	B200(): Behaviour(200,	// ID
					  2,		// Tree ID
					  true,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs

	},
					  {		// Expected outputs
		20000, // S-200-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_200_hpp */
