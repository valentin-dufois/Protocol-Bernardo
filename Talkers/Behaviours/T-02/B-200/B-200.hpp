//
//  B-200.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_200_hpp
#define B_200_hpp

#ifdef B200
#undef B200
#endif

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
		20001, // S-200-01
		20002, // S-200-02
	}) {}

	virtual bool execute(Machine * machine) override {
		_state["RAND"] = (double)rand() / (double)RAND_MAX;
		std::cout << std::get<double>(_state["RAND"]) << std::endl;
		return true;
	}
};


#endif /* B_200_hpp */
