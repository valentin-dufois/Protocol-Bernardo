//
//  LayoutEngine.cpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-21.
//

#include "LayoutEngine.hpp"
#include "../main.hpp"

#include <cstdio>
#include <algorithm>

#include "Structs/Layout.hpp"
#include "../../Common/Utils/DiskIO.hpp"
#include "../../Common/Utils/maths.hpp"
#include "../../Common/Utils/flags.hpp"

LayoutEngine::LayoutEngine():
_savePath(std::string(getenv("HOME")) + "/pb-layouts/") {
	LOG_DEBUG("Save path is " + std::string(_savePath));

	if(FLAGS_layout.size() > 0) {
		openLayout(FLAGS_layout);
	}
}

std::vector<std::string> LayoutEngine::getLayouts() {
	// Start by making sure the save folder exists
	if(DiskIO::mkdir(_savePath)) {
		LOG_INFO("Created layouts save directory");

		// No need to parse the folder as we have just created it
		return std::vector<std::string>();
	}

	// Parse the folder for layouts
	LOG_DEBUG("Parsing for existing layouts");

	std::vector<std::string> layouts;

	// For each entry in the folder
	for(std::string entry: DiskIO::ls(_savePath)) {

		// Check the extension match a PB Layout
		if(entry.substr(entry.size() - 9) != LAYOUT_EXT) {
			LOG_DEBUG("Not a layout");
			continue;
		}

		// Register it
		layouts.push_back(entry.substr(0, entry.size() - 9));
		LOG_DEBUG("Found : " + entry);
	}

	return layouts;
}

layout::Layout * LayoutEngine::createLayout(const std::string &name) {
	// Create a layout
	layout::Layout * layout = new layout::Layout();
	layout->name = name;

	// Create the layout directory
	DiskIO::mkdir(_savePath.string() + name + LAYOUT_EXT);

	// Save the layout to the disk
	messages::Layout layoutMessage = *layout;
	DiskIO::write(layoutPathFromName(name) + "/layout", &layoutMessage);

	return openLayout(name);
}

layout::Layout * LayoutEngine::openLayout(const std::string &name) {
	// Close any already opened layout
	if(_activeLayout != nullptr)
		closeLayout();

	LOG_DEBUG("Opening layout " + name + "...");

	// Load the layout from the disk
	_activeLayout = new layout::Layout(
		DiskIO::read<messages::Layout>(
			layoutPathFromName(name) + "/layout"
		)
	);

	LOG_INFO("Active layout is now " + name);

	return _activeLayout;
}

void LayoutEngine::renameLayout(const std::string &newName) {
	if(_activeLayout == nullptr) {
		LOG_ERROR("A layout must be opened to rename it");
		return;
	}

	LOG_DEBUG("Renaming active layout " + _activeLayout->name + " to " + newName + "...");

	// Rename the layout folder
	DiskIO::rename(layoutPathFromName(_activeLayout->name),
				   layoutPathFromName(newName));

	LOG_INFO("Active layout renamed to " + newName);

	// Rename the layout in memory
	_activeLayout->name = newName;
}

void LayoutEngine::updateLayout(layout::Layout *layout) {
	if(_activeLayout == nullptr) {
		LOG_ERROR("A layout must be opened to update it");
		return;
	}

	LOG_DEBUG("Updating active layout...");

	// Update the opened layout
	_activeLayout = layout;

	// Save the new version on the disk
	messages::Layout layoutMessage = *_activeLayout;
	DiskIO::write(layoutPathFromName(_activeLayout->name) + "/layout", &layoutMessage);

	LOG_INFO("Updated layout saved to disk");
}

void LayoutEngine::closeLayout() {
	LOG_INFO("Closing active layout...");
	_activeLayout = nullptr;
}

std::vector<std::string> LayoutEngine::deleteLayout(const std::string &name) {
	if(_activeLayout != nullptr) {
		if(_activeLayout->name == name)
			closeLayout();
	}

	LOG_DEBUG("Removing layout " + name + "...");

	DiskIO::rm(layoutPathFromName(name), true);

	LOG_DEBUG("Layout removed");

	return getLayouts();
}

// MARK: - Accessors

layout::Device * LayoutEngine::getDeviceByPhysicalUID(const pb::deviceUID &uid) {
	if(!hasActiveLayout()) {
		LOG_ERROR("An active layout is required for this method");
		return nullptr;
	}
	
	std::vector<layout::Device *>::iterator it = std::find_if(_activeLayout->devices.begin(),
													  _activeLayout->devices.end(),
													  [uid] (const layout::Device * device) {
		return device->physicalUID == uid;
	});

	return it == _activeLayout->devices.end() ? nullptr : *it;
}


// MARK: - Mathematics

Skeleton * LayoutEngine::
inGlobalCoordinates(const Skeleton &s, const pb::deviceUID deviceUID) {
	Skeleton * skeleton = new Skeleton();

	for(int i = 0; i < s.joints.size(); ++i) {
		skeleton->joints[i] = inGlobalCoordinates(s.joints[i], deviceUID);
	}

	skeleton->centerOfMass = inGlobalCoordinates(vec3(-s.centerOfMass.x, s.centerOfMass.y, s.centerOfMass.z), deviceUID);

	return skeleton;
}

Joint LayoutEngine::inGlobalCoordinates(const Joint &j, const pb::deviceUID deviceUID) {
	Joint joint = j;

	joint.position = inGlobalCoordinates(vec3(-j.position.x, j.position.y, j.position.z), deviceUID);

	return joint;
}

vec3 LayoutEngine::inGlobalCoordinates(const vec3 &local, const pb::deviceUID deviceUID) {
	if(!hasActiveLayout()) {
		LOG_ERROR("An active layout is required for this method");
		return vec3(0, 0, 0);
	}

	layout::Device * device = getDeviceByPhysicalUID(deviceUID);

	if(device == nullptr) {
		LOG_WARN("Cannot infer global coordinates for the device " + deviceUID);
		LOG_WARN("Device " + deviceUID + " is not matched for the current layout");
		return vec3(0, 0, 0);
	}

	vec3 global(0, 0, 0);
	SCALAR orientation = maths::deg2rad(device->orientation.z);

	// X and Z coordinates takes into account the angle of the device
	global.x = local.x * cos(orientation) - local.z * sin(orientation);
	global.z = local.x * sin(orientation) + local.z * cos(orientation);

	// Take into account the device position
	global.x += device->position.x * 10.0; // cm to mm
	global.z += device->position.y * 10.0; // cm to mm

	// Y position (Height) is not affected by the angle of capture
	global.y = local.y + device->position.z * 10.0; // cm to mm

	return global;
}
