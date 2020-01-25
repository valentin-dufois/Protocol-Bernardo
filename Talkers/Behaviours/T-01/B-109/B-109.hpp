//
//  B109.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B109_h
#define B109_h

#include "../../Behaviour.hpp"

class B109: public Behaviour {
public:
	B109(): Behaviour(109,	// ID
					  1,		// Tree ID
					  false,	// Is tree start ?
					  false,	// Force start ?
					  {		// Expected inputs
	},
					  {		// Expected outputs
		10900 // S-109-00
	}) {}
	
	virtual bool execute(Machine * machine) override {
		uint questionCount = 0;

		for(const std::string &caption: machine->receptionHistory()) {
			questionCount += std::count(caption.begin(), caption.end(), '?');
		}

		_state["NBR_QUESTIONS"] = (int)questionCount;
		return true;
	};
};


#endif /* B109_h */
