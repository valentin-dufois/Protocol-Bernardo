
//
//  CommunicationEngine.hpp
//  CommunicationEngine
//
//  Created by Valentin Dufois on 2019-09-09.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef CommunicationEngine_hpp
#define CommunicationEngine_hpp

#include <thread>
#include <vector>
#include <boost/asio.hpp>

#include "NetworkParameters.h"
#include "Endpoint.hpp"

namespace asio = boost::asio;

/// The communicaiton engine provides means of exchanging content between all the machines of PB.
class CommunicationEngine {
public:

	// MARK: - Singleton

	/// Singleton accessor
	static CommunicationEngine * instance() {
		if(_instance == nullptr)
			_instance = new CommunicationEngine();

		return _instance;
	}

	// MARK: - Static informations

	/// Provides an `Endpoint` reflecting the current machine. It uses the
	/// `thisMachineType` parameter inside it
	inline static Endpoint thisMachine() {
		return Endpoint("127.0.0.1", asio::ip::host_name(), thisMachineType);
	};

	/// The machine type should be defined as soon as possible at the start of the application.
	static Endpoint::Type thisMachineType;

	// MARK: - Communication Context

	/// Gives the underlying asio context. If the context does not exists, the context is created but not run. You have to call `runContext()` to run it asynchronously.
	inline asio::io_context & getContext() {
		return _ioContext;
	}

	/// Run the asio context on another context for asynchronous networking. This emthod handles calling run on an already running context. Basically, you should call this method everytime you finish setting up new services
	void runContext();

	std::vector<asio::ip::address> getOutboundInterfaces();

private:

	// MARK: - Singleton Properties

	/// The singleton instance of the Communication Engine
	static CommunicationEngine * _instance;

	// MARK: - Communication Context Properties

	/// The asio context
	asio::io_context _ioContext;

	/// The thread on which the asio context is running
	std::thread * _executionThread = nullptr;

};

#endif /* CommunicationEngine_hpp */
