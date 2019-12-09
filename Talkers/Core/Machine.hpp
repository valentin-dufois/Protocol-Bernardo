//
//  Machine.hpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#ifndef Machine_hpp
#define Machine_hpp

#include <functional>
#include <array>
#include <deque>

#include "Tree.hpp"
#include "../../Common/Utils/Arena.hpp"

// Watchers
#include "../Watchers/ClosePeopleWatcher.hpp"
#include "../Watchers/NoMovementsWatcher.hpp"
#include "../Watchers/RandomWatcher.hpp"
#include "../Watchers/SuddenMoveWatcher.hpp"

struct Message;
class Behaviour;
class MachineDelegate;

class Machine {
public:

	std::string label;

	MachineDelegate * delegate = nullptr;

	// MARK: - In
	void onMessage(Message * message);

	inline void
	setArena(pb::Arena arena) {
		_arena = arena;
	}

	// MARK: - Out
	
	void print(std::string);

	void say(std::string);

	// MARK: - Data access

	inline Tree * getTree() {
		return _tree;
	}

	inline pb::Arena * arena() {
		return &_arena;
	}

	inline const std::vector<std::string> & receptionHistory() {
		return _receptionHistory;
	}

	inline const std::deque<Event> & eventsHistory() {
		return _events;
	}

	// MARK: - Manual getters

	int getIntValue(const std::string &value);

	double getDoubleValue(const std::string &value);

	bool getBoolValue(const std::string &value);

	// MARK: - Watchers

	bool executeWatchers();

private:

	// MARK: - Properties

	Tree * _tree = nullptr;

	void onError();

	pb::Arena _arena;

	std::vector<std::string> _receptionHistory;

	std::deque<Event> _events;

	// MARK: - Watchers

	std::array<Watcher *, 4> _watchers = {
		new NoMovementsWatcher(100, 100, 1.0),
		new SuddenMoveWatcher(200, 2000, 1.0),
		new ClosePeopleWatcher(300, 1000, 1.0),
		new RandomWatcher(400, 0.001)
	};
};

#endif /* Machine_hpp */
