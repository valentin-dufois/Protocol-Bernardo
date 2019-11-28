//
//  Core.hpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2019-11-28.
//

#ifndef Core_hpp
#define Core_hpp

#include "Machine.hpp"

class Core {
public:
	// MARK: - Lifecycle

	Core() = default;

	void init();

	void run();

	void terminate();

	~Core();

private:

	bool _isRunning = false;

	Machine _machineA;
	Machine _machineB;
};

#endif /* Core_hpp */
