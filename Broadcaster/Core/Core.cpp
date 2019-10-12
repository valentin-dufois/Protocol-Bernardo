//
//  Core.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-22.
//

#include "Core.hpp"

void Core::init() {

}

void Core::run() {

}

void Core::cadence(std::chrono::high_resolution_clock::time_point start, std::chrono::high_resolution_clock::time_point end)
{
	std::chrono::milliseconds elapsed, toWait;

	// How long did the last rendering took ?
	elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	// Is this more than the length of a frame
	if(elapsed.count() < FRAMERATE)
	{
		// Wait for the remaining time
		toWait = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::milliseconds(FRAMERATE) - elapsed);
		std::this_thread::sleep_for(toWait);
	}
}
