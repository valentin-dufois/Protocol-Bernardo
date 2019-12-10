//
//  Log.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-18.
//

#ifndef Log_h
#define Log_h

#ifndef LOG_LEVEL
#define LOG_LEVEL 5 // If not LOG_LEVEL defined, no logs
#endif

#if LOG_LEVEL == 1
// #warning "All logs are activated. This can reduce the app performances."
#include <filesystem>
#endif


#include <iostream>
#include <string>

/// Provides an easy and coherent way for all PB applications to log informations
namespace pb {
namespace Log {

/// Specify the current logging level.
enum Level: int {
	DEV = 1,
	INFO = 2,
	WARNING = 3,
	LOGLEVEL_ERROR = 4,
	NONE = 5
};

#if LOG_LEVEL > 0

/// Build the location prefix with the filename and line from where the logs are comming
inline std::string locat(const std::string &, const int &) {
	// Do not show the error location when not debugging
		return "";
}

#else

/// Build the location prefix with the filename and line from where the logs are comming
inline std::string locat(const std::string &file, const int &line) {
	std::string filename = std::filesystem::path(file).filename();
	return " [" + filename + ":" + std::to_string(line) + "] ";
}

#endif

/// Raw method to log informations. Commonly used by all other logging methods.
/// Supports all formats supported by `std::cout`
template<typename T>
void raw(const T &log) {
	std::cout << log << std::endl;
}

/// Log something as a debug statement
inline void debug(const std::string &log, const std::string &file = "", const int &line = -1) {
	if(LOG_LEVEL <= 1)
		raw("➡️  " + locat(file, line) + log);
}

/// Log something as informative
inline void info(const std::string &log, const std::string &file = "", const int &line = -1) {
	if(LOG_LEVEL <= 2)
		raw("📢 " + locat(file, line) + log);
}

/// Log something as a warning
inline void warning(const std::string &log, const std::string &file = "", const int &line = -1) {
	if(LOG_LEVEL <= 3)
		raw("⚠️ " + locat(file, line) + log);
}

/// Log something as an error
inline void error(const std::string &log, const std::string &file = "", const int &line = -1) {
	if(LOG_LEVEL <= 4)
		raw("❌ " + locat(file, line) + log);
}

} /* ::Log */
} /* ::pb */

// MARK: - Log Macros

#define LOG_DEBUG(s) pb::Log::debug(s, __FILE__, __LINE__)

#define LOG_INFO(s) pb::Log::info(s, __FILE__, __LINE__)

#define LOG_WARN(s) pb::Log::warning(s, __FILE__, __LINE__)

#define LOG_ERROR(s) pb::Log::error(s, __FILE__, __LINE__)

#endif /* Log_h */
