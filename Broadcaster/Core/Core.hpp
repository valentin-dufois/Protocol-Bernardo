//
//  Core.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-22.
//

#ifndef Core_hpp
#define Core_hpp

// Framerate
#define FPS 60
#define FRAMERATE 1000/FPS

#include <thread>
#include <chrono>

class Core {
public:
	/// Run only one time at the start of the app
	void init();

	/// Hold the main loop of the application
	void run();
	
private:

	// MARK: - Cadencing

	/**
	 Periodically pause the main loop to cadence the framerate to the specified one.

	 By taking the start and end time of the last rendering time, `cadence` pause
	 this thread for the remaining time ot reach 1/FRAMERATE of second

	 @param start start of the last rendering task
	 @param end end of the last rendering task
	 */
	void cadence(std::chrono::high_resolution_clock::time_point start, std::chrono::high_resolution_clock::time_point end);
};

#endif /* Core_hpp */
