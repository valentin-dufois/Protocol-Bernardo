//
//  LayoutEngine.cpp
//  pb-acquisitor
//
//  Created by Valentin Dufois on 2019-09-21.
//

#include "LayoutEngine.hpp"

#include <cstdio>

#include "Structs/Layout.hpp"

#define LAYOUT_EXT ".pblayout"

LayoutEngine::LayoutEngine():
_savePath(std::string(getenv("HOME")) + "/pb-layouts/") {
	LOG_DEBUG("Save path is " + std::string(_savePath));
	getLayouts();
}

std::vector<std::string> LayoutEngine::getLayouts() {
	// Start by making sure the save folder exists
	if(!fs::exists(_savePath)) {
		LOG_INFO("Creating layouts save directory");
		fs::create_directory(_savePath);

		// No need to parse the folder as we have just created it
		return std::vector<std::string>();
	}

	// Parse the folder for layouts
	LOG_INFO("Parsing for existing layouts");

	std::vector<std::string> layouts;

	for(fs::directory_entry entry: fs::directory_iterator(_savePath)) {
		layouts.push_back(entry.path().filename());
		LOG_INFO("Found directory entry : " + std::string(entry.path()));
	}

	return layouts;
}

layout::Layout * LayoutEngine::createLayout(const std::string &name) {
	// Create a layout
	layout::Layout * layout = new layout::Layout();
	layout->name = name + LAYOUT_EXT;

	// Save the layout to the disk
	

	return openLayout(name);
}

layout::Layout * LayoutEngine::openLayout(const std::string &name) {
	return new layout::Layout();
}

void LayoutEngine::renameLayout(const std::string &newName) {
}


