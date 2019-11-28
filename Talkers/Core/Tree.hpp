//
//  Tree.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-28.
//

#ifndef Tree_h
#define Tree_h

#include "../Utils/StateValue.hpp"

class Tree {
public:
	Tree(unsigned int treeID): _id(treeID) {};

	inline unsigned int getID() const { return _id; }

	State state;

private:
	unsigned int _id;
};

#endif /* Tree_h */
