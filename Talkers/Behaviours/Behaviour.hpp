
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

#include "../main.hpp"

class Tree;
class Output;
struct Message;
class Machine;

class Behaviour {
public:

	Behaviour(const talkers::BehaviourID id,
			  const talkers::TreeID treeID,
			  const bool isTreeStart,
			  const bool forceStart,
			  const std::vector<std::string> expectedInputs,
			  const std::vector<talkers::OutputID> possibleOutputs):
	id(id),
	treeID(treeID),
	isTreeStart(isTreeStart),
	forceStart(forceStart),
	_expectedInputs(expectedInputs),
	_possibleOutputs(possibleOutputs) {}

	/// Gives the requested behaviour
	static Behaviour * get(const talkers::BehaviourID id);

	// MARK: - Identification

	/// Unique ID of the behaviour
	const talkers::BehaviourID id;

	// MARK: - Tree

	/// Access to the current tree
	Tree * tree;

	/// ID of the tree
	const talkers::TreeID treeID;

	/// Tell if this behaviour is the beggining of a tree
	const bool isTreeStart;

	/// Tell if this behaviour override the current tree
	const bool forceStart;


	// MARK: - LifeCycle

	/// Get the values from the given message and validate it against
	/// the expected inputs.
	///
	/// @returns True if import was successful or false if there was an error
	bool importMessage(Message * message);

	/// Executes the behaviour actions and update its state accordingly
	///
	/// @params machine the machine on which we are executing
	/// @returns True if execution was successful or false if there was an error
	virtual bool execute(Machine * machine) = 0;

	/// Gives the output for this behaviour based on the current inner state
	Output * getOutput();

	virtual ~Behaviour() {}

protected:
	/// List of expected inputs
	const std::vector<std::string> _expectedInputs;

	/// List of possible outputs
	const std::vector<talkers::OutputID> _possibleOutputs;

	/// The inner state of the behaviour
	State _state;
};

#endif /* Behaviour_hpp */
