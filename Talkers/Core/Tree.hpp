//
//  Tree.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-28.
//

#ifndef Tree_h
#define Tree_h

#include "../main.hpp"

/// A tree is used in a conversation to store information that may be used later on in the same conversation. Additionally, Tree are used to check for error when going through a conversation
struct Tree {
	Tree(talkers::TreeID treeID): id(treeID) {};

	/// ID of the tree
	const talkers::TreeID id;

	/// Internal state of the tree
	State state;
};

#endif /* Tree_h */
