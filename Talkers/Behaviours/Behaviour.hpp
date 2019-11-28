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

#include "StateValue.hpp"

class Tree;
class Output;
class Message;

class Behaviour {
public:
	// MARK: - Identification

	/// Unique ID of the behaviour
	const unsigned int id;

	// MARK: - Tree;

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
	virtual bool importMessage(Message *);

	/// Executes the behaviour actions and update its state accordingly
	///
	/// @returns True if execution was successful or false if there was an error
	virtual bool execute() = 0;

	/// Gives the output for this behaviour based on the current inner state
	virtual Output * getOutput() = 0;

protected:
	/// List of exepcted inputs
	const std::vector<std::string> expectedInputs;

	/// The inner state of the behaviour
	State _state;

	// MARK: - Outputs
};

#endif /* Behaviour_hpp */
