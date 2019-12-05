//
//  Machine.hpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#ifndef Machine_hpp
#define Machine_hpp

#include <functional>

#include "Tree.hpp"
#include "../Utils/AccessibleValues.hpp"

class Message;
class Behaviour;

class Machine {
public:

	std::string label;

	// MARK: - In
	void onMessage(Message * message);

	// MARK: - Out
	std::function<void(Message * message)> sendMessage;

	void print(std::string);

	void say(std::string);

	// MARK: - Data access

	int getIntValue(const AccessibleValues &value);

	double getDoubleValue(const AccessibleValues &value);

	bool getBoolValue(const AccessibleValues &value);

	std::string getStringValue(const AccessibleValues &value);

private:

	// MARK: - Properties

	Tree * _tree = nullptr;

	void onError();

	// MARK: - Manual data access

	int getIntValueManually(const AccessibleValues &value);

	double getDoubleValueManually(const AccessibleValues &value);

	bool getBoolValueManually(const AccessibleValues &value);

	std::string getStringValueManually(const AccessibleValues &value);
};

#endif /* Machine_hpp */
