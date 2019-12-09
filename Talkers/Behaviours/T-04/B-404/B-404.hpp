//
//  B-404.hpp
//  pb-common (shared)
//
//  Created by Marie-Lou on 2019-12-07.
//

#ifndef B404_h
#define B404_h

#include "../../Behaviour.hpp"
#include "../../../Core/Machine.hpp"

class B404 : public Behaviour {
public:
	B404() : Behaviour(404,		// ID
		4,		// Tree ID
		false,	// Is tree start ?
		false,	// Force start ?
		{		// Expected inputs
		},
		{		// Expected outputs
		40400 // S-404-00
		}) {}

	virtual bool execute(Machine * machine) override {
		machine->say("Nous connaissons nos limitations en termes de perception et acceptons une marge d'erreur.");
		return true;
	}
};


#endif /* B404_h */
