//
//  Tree.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-28.
//

#ifndef Tree_h
#define Tree_h

#include "../main.hpp"
#include "../Utils/StateValue.hpp"

class Tree {
public:
	Tree(talkers::TreeID treeID): _id(treeID) {};

	inline talkers::TreeID getID() const { return _id; }

	State state;

private:
	talkers::TreeID _id;
};

#endif /* Tree_h */
