//
//  B-202.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_202_hpp
#define B_202_hpp


#include "../../Behaviour.hpp"

class B202: public Behaviour {
public:
	B202(): Behaviour(202,	// ID
					  2,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		20200, // S-202-00
	}) {}

	virtual bool execute(Machine * machine) override {
		return true;
	}
};


#endif /* B_202_hpp */
