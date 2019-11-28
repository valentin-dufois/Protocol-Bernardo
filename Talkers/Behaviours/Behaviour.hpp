//
//  Behaviour.hpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-27.
//

#ifndef Behaviour_hpp
#define Behaviour_hpp

#include <string>
#include <vector>

#include "../Utils/StateValue.hpp"

class Tree;
class Output;
class Message;
class Machine;

class Behaviour {
public:

	static Behaviour * get(const unsigned int id);

	// MARK: - Identification

	/// Unique ID of the behaviour
	unsigned int id;

	// MARK: - Tree

	/// Access to the current tree
	Tree * tree;

	/// ID of the tree
	unsigned int treeID;

	/// Tell if this behaviour is the beggining of a tree
	bool isTreeStart;

	/// Tell if this behaviour override the current tree
	bool forceStart;


	// MARK: - LifeCycle

	/// Get the values from the given message and validate it against
	/// the expected inputs.
	///
	/// @returns True if import was successful or false if there was an error
	virtual bool importMessage(Message * message);

	/// Executes the behaviour actions and update its state accordingly
	///
	/// @params machine the machine on which we are executing
	/// @returns True if execution was successful or false if there was an error
	virtual bool execute(Machine * machine) = 0;

	/// Gives the output for this behaviour based on the current inner state
	virtual Output * getOutput();

	virtual ~Behaviour() {}

protected:
	/// List of expected inputs
	std::vector<std::string> _expectedInputs;

	/// List of possible outputs
	std::vector<unsigned int> _possibleOutputs;

	/// The inner state of the behaviour
	State _state;
};

#endif /* Behaviour_hpp */
