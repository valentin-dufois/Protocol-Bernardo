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

	void onSay(const std::string &caption);

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

	inline std::set<pb::bodyUID> getAllBodyUID() {
		return _bodyUIDHistory;
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

	std::set<pb::bodyUID> _bodyUIDHistory;

	// MARK: - Watchers

	std::array<Watcher *, 7> _watchers = {
		new NoMovementsWatcher(100, 50, 0.1),
		new SuddenMoveWatcher(200, 5000, 0.1),
		new ClosePeopleWatcher(300, 800, 0.1),
		new RandomWatcher(400, 0.01),
		new RandomWatcher(500, 0.01),
		new RandomWatcher(600, 0.01),
		new RandomWatcher(800, 0.01)
	};
};

#endif /* Machine_hpp */
