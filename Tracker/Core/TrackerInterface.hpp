//
//  TrackerInterface.hpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2020-01-18.
//

#ifndef TrackerInterface_hpp
#define TrackerInterface_hpp

#include <vector>
#include <map>

#include "../../Common/UI/utils/Display.hpp"
#include "../../Common/UI/utils/ncurses.hpp"

#include "../../Common/UI/Elements.hpp"

#include "../PoseEstimationEngine/Devices/Device.hpp"

namespace pb {
namespace tracker {

class TrackerInterface: public ui::Display {
public:

	TrackerInterface();

	void registerDevice(const tracker::Device * device);

	void setSocketConnected(const bool isConnected);

private:

	// Dynamic interface elements holds
	ui::PBLabel * _masterConnectivityStatus = nullptr;
	ui::PBLabel * _tablePlaceholder = nullptr;

	std::vector<ui::PBLabel *> _devicesLabels;
};

} /* ::tracker */
} /* ::pb */

#endif /* TrackerInterface_hpp */
