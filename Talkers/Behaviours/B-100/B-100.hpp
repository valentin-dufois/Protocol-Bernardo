//
//  B-100.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef B_100_hpp
#define B_100_hpp


#include "../Behaviour.hpp"

class B100: public Behaviour {
	unsigned int id = 100;

	unsigned int treeID = 1;

	bool isTreeStart = true;

	bool forceStart = false;

	virtual bool execute(Machine * machine) override;

	std::vector<std::string> _expectedInputs = {};

	std::vector<unsigned int> _possibleOutputs = {
		10000 // S-100-00
	};
};


#endif /* B_100_hpp */
