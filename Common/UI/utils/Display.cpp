//
//  Display.cpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2020-01-16.
//

#include "Display.hpp"

#include "../../Utils/thread.hpp"
#include "ncurses.hpp"

namespace ui {

void Display::display() {
	if(_isShown)
		return; // Display already shown

	_isShown = true;

	ui::nCurses::init();

	if(_renderThread != nullptr)
		delete _renderThread;

	// Create the render frame and run it
	_renderThread = new std::thread([&] () {
		pb::thread::setName("prisme.ui.render");

		while(_isShown) {
			std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

			_renderMutex.lock();

			nC::clear();
			nC::clearWindow();
			render();
			refresh();

			_renderMutex.unlock();

			std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

			pb::thread::cadence(end - start, _refreshRate);
		}
	});
}

void Display::hide() {
	_isShown = false;
}

Display::~Display() {
	hide();

	if(_renderThread != nullptr)
		delete _renderThread;
}

}
