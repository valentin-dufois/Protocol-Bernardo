//
//  main.cpp
//  pb-tracker-launcher
//
//  Created by Valentin Dufois on 2019-10-11.
//

#include <iostream>
#include <cstdlib>
#include <boost/process.hpp>
#include "../Common/Utils/Log.hpp"

boost::process::child tracker;

void exiting() {
	LOG_INFO("Quitting the Tracker laucher");

	if(tracker.running())
		tracker.terminate();
}

int main(int argc, const char * argv[]) {

	// Update usb parameters to support mulitple devices
	std::system("sh -c 'echo 256 > /sys/module/usbcore/parameters/usbfs_memory_mb");

	std::atexit(exiting);

	int exitCode = -1;
	// Indefinitely loop to restart the process if it crashes
//	do {
		LOG_INFO("Starting the Tracker...");

		// Start the tracker
		tracker = boost::process::child("./pb-tracker");
		tracker.wait();

		// Get its exit code
		exitCode = tracker.exit_code();
		LOG_INFO("Tracker closeed with exit code " + std::to_string(exitCode));
//	} while(exitCode != 0);

//	return 0;
}
