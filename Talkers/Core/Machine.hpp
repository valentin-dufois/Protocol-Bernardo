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

class Message;
class Behaviour;

class Machine {
public:

	std::string label;

	// IN
	void onMessage(Message * message);

	// OUT
	std::function<void(Message *)> sendMessage;

	void print(std::string);

private:
	Tree * _tree = nullptr;

	void onError();
};

#endif /* Machine_hpp */
