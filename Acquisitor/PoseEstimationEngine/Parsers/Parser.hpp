//
//  Parser.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-09-20.
//

#ifndef Parser_h
#define Parser_h

// Forward declaration
class Device;

/// A parser uses the driver capabilities to scan connected devices and open
/// connection with compatible devices
class Parser {
public:
	// This method will be called everytime a new device is found
	std::function<void(const Device *)> onNewDevice;

	/// Starts the parser
	virtual void start() = 0;
};

#include "OpenNIParser.hpp"

#endif /* Parser_h */
