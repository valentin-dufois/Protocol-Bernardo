//
//  NiteTracker.hpp
//  pb-tracker
//
//  Created by Valentin Dufois on 2019-09-18.
//

#ifndef NiteTracker_hpp
#define NiteTracker_hpp

#include <boost/asio.hpp>

#include "Tracker.hpp"

#include "../Devices/OpenNIDevice.hpp"

namespace pb {
namespace tracker {

/// Takes an OpenNI device and do pose estimation with it. The Tracker
/// is considered as owning the device, and will therefore free it on destruction
class NiteTracker:
	public Tracker,
	public nite::UserTracker::NewFrameListener
{
public:
	NiteTracker(OpenNIDevice *);

	inline OpenNIDevice * getDevice() override { return _device; }
	
	~NiteTracker();

private:
	OpenNIDevice * _device;

	/// Called by NiTE everytime a new frame has been processed
	/// @param tracker The usertracker processing the frame
	void onNewFrame(nite::UserTracker &tracker) override;

	/// Process the frame, go from a nite format to our own and propagate informations
	/// @param frame The nite frame to process
	void processFrame(nite::UserTrackerFrameRef * frame);

	/** Human pose tracker (NiTE) */
	nite::UserTracker _tracker;
};

} /* ::tracker */
} /* ::pb */

#endif /* NiteTracker_hpp */
