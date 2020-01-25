//
//  Display.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2020-01-16.
//

#ifndef Display_hpp
#define Display_hpp

#include <thread>
#include <mutex>
#include <atomic>

#include "../Scene.hpp"

namespace ui {

class Display: public Scene {
public:

	/// Display this display on the screen, starting the render loop
	void display();

	/// Stops displaying the display and kills the renderloop
	void hide();

	~Display();

protected:

	// Make scene render method protected to prevent usage from outside
	using Scene::render;

	/// Display refresh rate
	const unsigned int _refreshRate = 15;

	/// Mutex used by the display to prevent race condition when rendering
	/// This mutex should be locked when modifying informations used by the render method.
	std::mutex _renderMutex;

private:

	std::atomic_bool _isShown = false;

	/// Thread used by the display for its render loop
	std::thread * _renderThread = nullptr;
};

} /* ::ui */

#endif /* Display_hpp */
