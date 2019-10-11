//
//  Log.cpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-18.
//

#include "Log.hpp"

#include <filesystem>

namespace Log {

Level level = Level::DEV;

void info(const std::string &log) {
	if(level >= 1)
		raw("📢 " + log);
}

void info(const std::string &log, const std::string &file, const int &line) {
	if(level >= 1)
		raw("📢" + locat(file, line) + log);
}

void warning(const std::string &log) {
	if(level >= 2)
		raw("⚠️ " + log);
}

void warning(const std::string &log, const std::string &file, const int &line) {
	if(level >= 2)
		raw("⚠️" + locat(file, line) + log);
}

void error(const std::string &log) {
	if(level >= 3)
		raw("❌ " + log);
}

void error(const std::string &log, const std::string &file, const int &line) {
	if(level >= 3)
		raw("❌" + locat(file, line) + log);
}

void debug(const std::string &log) {
	if(level >= 4)
		raw("➡️ " + log);
}

void debug(const std::string &log, const std::string &file, const int &line) {
	if(level >= 4)
		raw("➡️" + locat(file, line) + log);
}

template<typename T>
void raw(const T &log) {
	std::cout << log << std::endl;
}

std::string locat(const std::string &file, const int &line) {
	// Do not show the error location when not debugging
	if(level < 4) {
		return " ";
	}

	std::string filename = std::filesystem::path(file).filename();
	return " [" + filename + ":" + std::to_string(line) + "] ";
}

}
