//
//  LayoutEngine.cpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-21.
//

#include "LayoutEngine.hpp"

#include <cstdio>

#include "Structs/Layout.hpp"
#include "../../Common/Utils/DiskIO.hpp"

LayoutEngine::LayoutEngine():
_savePath(std::string(getenv("HOME")) + "/pb-layouts/") {
	LOG_DEBUG("Save path is " + std::string(_savePath));
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


