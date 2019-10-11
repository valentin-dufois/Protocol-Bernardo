//
//  TimeoutHandling.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-10-02.
//

#ifndef TimeoutHandling_h
#define TimeoutHandling_h

#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "../NetworkParameters.h"
#include "../CommunicationEngine.hpp"

namespace asio = boost::asio;

class TimeoutHandling {
protected:

	TimeoutHandling(): _timer(CommunicationEngine::instance()->getContext()) {}

	inline void startTimer() {
		_timer.expires_from_now(boost::posix_time::seconds(10));
		_timer.async_wait([&] (const boost::system::error_code &error) {
			// Operation aborted is send if the timer is cancelled, meaning no timeout
			if(error != boost::asio::error::operation_aborted)
				onTimeout(error);
		});
	}

	inline void endTimer() {
		_timer.cancel_one();
	}

	virtual void onTimeout(const boost::system::error_code& error) = 0;

private:

	asio::deadline_timer _timer;
};

#endif /* TimeoutHandling_h */
