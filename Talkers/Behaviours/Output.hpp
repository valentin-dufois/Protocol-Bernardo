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

#include "../main.hpp"
#include "Behaviour.hpp"

#define DELAY_DEFAULT true
#define DELAY_VALUE_DEFAULT 6.5
#define DELAY_VARIANCE_DEFAULT .5

struct Message;

struct Output {
public:

	Output(const talkers::OutputID id,
		   const bool isTreeEnd,
		   const talkers::BehaviourID nextBehaviour,
		   const bool isDelayed,
		   const double delayValue,
		   const double delayVariance,
		   const std::vector<std::string> outputValues,
		   const std::vector<std::string> captions):
	id(id),
	isTreeEnd(isTreeEnd),
	_nextBehaviour(nextBehaviour),
	_isDelayed(isDelayed),
	_delayValue(delayValue),
	_delayVariance(delayVariance),
	_outputValues(outputValues),
	_captions(captions) {}

	/// Gives the requested output
	static Output * get(const talkers::OutputID id);

	/// ID of the current output
	const talkers::OutputID id;

	/// Tell if this output means the end of the tree on this machine
	const bool isTreeEnd;

	/// Tell if the current behaviour state match the condition of this output
	virtual bool isConditionValid(State &behaviourState) = 0;

	/// Gives the delay before sending the message
	virtual double getDelay() const;

	/// Gives the message corresponding to this output
	/// If no message should be sent because this is an end, you should override this method and return nullptr;
	Message * getMessage() const;

	virtual ~Output() {}

protected:

	/// The inner state of the output
	mutable State _state;

	/// The next behaviour id, if any
	const talkers::BehaviourID _nextBehaviour;

	/// Tell if the output message should be delayed or not
	const bool _isDelayed;

	/// The delay value in seconds
	const double _delayValue;

	/// The delay variance in seconds
	const double _delayVariance;

	/// Output values needed to build the output message
	const std::vector<std::string> _outputValues;

	/// Available captions to form the output message
	const std::vector<std::string> _captions;

	/// Gives the caption to insert in the message
	std::string getCaption() const;
};

#endif /* Output_h */
