//
//  Output.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-27.
//

#ifndef Output_h
#define Output_h

#include <vector>
#include <string>
#include <map>

#include "Behaviour.hpp"

struct Message;

struct Output {
public:

	/// Tell if this output means the end of the tree on this machine
	bool isTreeEnd;

	/// Tell if the current behaviour state match the condition of this output
	virtual bool isConditionValid(const State &behaviourState) = 0;

	/// Gives the delay before sending the message
	virtual double getDelay();

	/// Gives the message corresponding to this output
	/// If no message should be sent because this is an end, you should override this method and return nullptr;
	virtual Message * getMessage();

protected:

	/// The inner state of the output
	State _state;

	/// Output values needed to build the output message
	std::vector<std::string> _outputValues;

	/// Available captions to form the output message
	std::vector<std::string> _captions;

	/// Tell if the output message should be delayed or not
	bool _isDelayed;

	/// The delay value in seconds
	double _delayValue;

	/// The delay variance in seconds
	double _delayVariance;

	/// The next behaviour id, if any
	unsigned int _nextBehaviour;

	/// Gives the caption to insert in the message
	std::string getCaption();
};

#endif /* Output_h */
