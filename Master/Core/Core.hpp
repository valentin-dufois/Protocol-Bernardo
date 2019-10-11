//
//  Core.hpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-21.
//

#ifndef Core_hpp
#define Core_hpp

#include "../LayoutEngine/LayoutEngine.hpp"
#include "NetworkManager.hpp"

class Core {
public:
	void init();

	void run();

//	void onAcquisitor(const AcquisitorClient * &acquisitor);
private:

	bool _isRunning = true;

	NetworkManager _networkManager;

	LayoutEngine _layoutEngine;
};

#endif /* Core_hpp */
