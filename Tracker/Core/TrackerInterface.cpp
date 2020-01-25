//
//  TrackerInterface.cpp
//  pb-common (shared)
//
//  Created by Valentin Dufois on 2020-01-18.
//

#include "TrackerInterface.hpp"

namespace pb {
namespace tracker {

TrackerInterface::TrackerInterface() {
	// Insert all static elements in the interface

	// Main Title
	ui::PBLabel * mainTitle = new ui::PBLabel("PB-TRACKER", ui::PBPoint(1, 1));
	mainTitle->isBold = true;
	getView()->addSubview(mainTitle);

	// Master connectivity label
	ui::PBLabel * masterLabel = new ui::PBLabel("Master:", ui::PBPoint(55, 1));
	masterLabel->isUnderlined = true;
	getView()->addSubview(masterLabel);

	// Table structure
	getView()->addSubview(new ui::PBHorizontalLine(ui::PBPoint(0, 3), 80));
	getView()->addSubview(new ui::PBHorizontalLine(ui::PBPoint(0, 5), 80));
	getView()->addSubview(new ui::PBHorizontalLine(ui::PBPoint(0, 22), 80));

	// Table headings
	getView()->addSubview(new ui::PBLabel("Device", ui::PBPoint(1, 4)));
	getView()->addSubview(new ui::PBLabel("Serial", ui::PBPoint(20, 4)));

	// Placeholder
	_masterConnectivityStatus = new ui::PBLabel("Searching...", ui::PBPoint(63, 1));
	getView()->addSubview(_masterConnectivityStatus);

	_tablePlaceholder = new ui::PBLabel("No devices connected...", ui::PBPoint(1, 7));
	getView()->addSubview(_tablePlaceholder);
}

void TrackerInterface::registerDevice(const tracker::Device * device) {
	if(_tablePlaceholder != nullptr) {
		_tablePlaceholder->removeFromSuperView();
		delete _tablePlaceholder;
	}

	_devicesLabels.push_back(new ui::PBLabel(device->getName(), ui::PBPoint(1, 6 + (int)(_devicesLabels.size()/2))));
	_devicesLabels.push_back(new ui::PBLabel(device->getUID(), ui::PBPoint(20, 5 + (int)(_devicesLabels.size()/2))));
}

void TrackerInterface::setSocketConnected(const bool isConnected) {
	if(isConnected) {
		_masterConnectivityStatus->setTitle("Connected");
		return;
	}

	_masterConnectivityStatus->setTitle("Searching...");
}

} /* ::tracker */
} /* ::pb */
