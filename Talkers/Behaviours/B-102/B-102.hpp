//
//  B000.hpp
//  Protocol Bernardo
//
//  Created by Marie-Lou Barbier on 2019-12-02.
//

#ifndef B102_h
#define B102_h

#include "../Behaviour.hpp"

class B102: public Behaviour {
	unsigned int id = 102;

	unsigned int treeID = 1;

	bool isTreeStart = false;

	bool forceStart = false;

	virtual bool execute(Machine * machine) override;

	/// List of expected inputs
	std::vector<std::string> _expectedInputs = {};

	/// List of possible outputs
	std::vector<unsigned int> _possibleOutputs = {
		10200 // S-102-00
	};
};


#endif /* B000_h */
