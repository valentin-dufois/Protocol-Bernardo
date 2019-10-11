//
//  main.cpp
//  pb-acquisitor-launcher
//
//  Created by Valentin Dufois on 2019-10-11.
//

#include <iostream>
#include <cstdlib>
#include <boost/process.hpp>
#include "../Common/Utils/Log.hpp"

boost::process::child acquisitor;

void exiting() {
	LOG_INFO("Quitting the Acquisitor laucher");

	if(acquisitor.running())
		acquisitor.terminate();
}

int main(int argc, const char * argv[]) {

	std::atexit(exiting);

	int exitCode = -1;
	// Indefinitely loop to restart the process if it crashes
	do {
		LOG_INFO("Starting the Acquisitor...");

		// Start the acquisitor
		acquisitor = boost::process::child("./pb-acquisitor", "--log-level=0");
		acquisitor.wait();

		// Get its exit code
		exitCode = acquisitor.exit_code();
		LOG_INFO("Acquisitor Ended with exit code " + std::to_string(exitCode));
	} while(exitCode != 0);

	return 0;
}
