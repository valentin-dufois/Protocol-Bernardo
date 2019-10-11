//
//  Log.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-18.
//

#ifndef Log_h
#define Log_h

#include <iostream>
#include <string>

/// Provides an easy and coherent way for all PB applications to log informations
namespace Log {

/// Specify the current logging level.
enum Level {
	NONE = 0,
	ERROR = 1,
	WARNING = 2,
	INFO = 3,
	DEV = 4
};

/// The current logging level
extern Level level;

/// Log something as informative
void info(const std::string &log, const std::string &file = "", const int &line = -1);

/// Log something as a warning
void warning(const std::string &log, const std::string &file = "", const int &line = -1);

/// Log something as an error
void error(const std::string &log, const std::string &file = "", const int &line = -1);

/// Log something as a debug statement
void debug(const std::string &log, const std::string &file = "", const int &line = -1);

/// Raw method to log informations. Commonly used by all other logging methods.
/// Supports all formats supported by `std::cout`
template<typename T>
void raw(const T &log);

std::string locat(const std::string &file, const int &line);

}
// MARK: - Log Macros

#define LOG_DEBUG(s) Log::debug(s, __FILE__, __LINE__)

#define LOG_INFO(s) Log::info(s, __FILE__, __LINE__)

#define LOG_WARN(s) Log::warning(s, __FILE__, __LINE__)

#define LOG_ERROR(s) Log::error(s, __FILE__, __LINE__)

#endif /* Log_h */
