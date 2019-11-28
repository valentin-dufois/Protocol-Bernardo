//
//  B000.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-28.
//

#ifndef B000_h
#define B000_h

#include "../Behaviour.hpp"

class B000: public Behaviour {
	unsigned int id = 0;

	unsigned int treeID = 0;

	bool isTreeStart = true;

	bool forceStart = true;

	virtual bool execute(Machine * machine) override;

	/// List of expected inputs
	std::vector<std::string> _expectedInputs = {};

	/// List of possible outputs
	std::vector<unsigned int> _possibleOutputs = { 000 };
};


#endif /* B000_h */
