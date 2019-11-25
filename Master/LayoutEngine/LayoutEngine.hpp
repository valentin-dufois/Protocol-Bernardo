//
//  LayoutEngine.hpp
//  pb-tracker
//
//  Created by Valentin Dufois on 2019-09-21.
//

#ifndef LayoutEngine_hpp
#define LayoutEngine_hpp

#define LAYOUT_DIRECTORY getenv("HOME")+"/pb-layouts/"

#include <vector>
#include <string>
#include <filesystem>

#include "../../Common/common.hpp"
#include "../../Common/Utils.hpp"
#include "../../Common/Structs/Skeleton.hpp"

#define LAYOUT_EXT ".pblayout"

namespace fs = std::filesystem;

namespace pb {
namespace layout {
class Layout;
class Device;
}

namespace master {

class LayoutEngine {
public:
	LayoutEngine();

	// MARK: - Layout Handling

	/// Gives the name of all the layouts
	/// @returns The list of layouts
	std::vector<std::string> getLayouts();

	/// Creates a new layout with the given name
	/// @param name Name of the new layout
	/// @returns The newly created layout
	layout::Layout * createLayout(const std::string &name);


	/// Open an existing layout with the given name
	/// @param name The layout name
	/// @returns The opened layou
	layout::Layout * openLayout(const std::string &name);

	/// Renames the currently opened layout to the given name
	/// @param newName The new name of the current layout
	void renameLayout(const std::string &newName);

	/// Update the currently opened layout with the given one
	/// @param layout The new version of the current layout
	void updateLayout(layout::Layout * layout);

	/// Close the currently opened layout
	void closeLayout();

	/// Delete the specified layout
	/// @param name Name of the layout to delete
	/// @returns The updated list of available layouts
	std::vector<std::string> deleteLayout(const std::string &name);

	// MARK: - Accessors

	/// Tell if there is a layout open
	inline bool hasActiveLayout() { return _activeLayout != nullptr; }

	/// Gives the currently active layout, Returns nullptr if no layou is open
	inline layout::Layout * activeLayout() { return _activeLayout; }

	/// Gives the corresponding layout device for the given physical device UID
	/// If no layout device matches the given UID, a nullptr will be returned
	/// @param uid The physical device UID
	layout::Device * getDeviceByPhysicalUID(const pb::deviceUID &uid);

	// MARK: - Mathematics


	/// Converts the given Skeleton from its local space to the global space.
	/// A skeleton joints 2D coordinates are irrelevant once on the global space
	/// @param s The skeleton to convert
	/// @param deviceUID The device UID of the skeleton local space
	Skeleton inGlobalCoordinates(const Skeleton &s, const pb::deviceUID deviceUID);

	/// Converts the given Joint from its local space to the global space.
	/// The joint 2D position is irrelevant after calling this method as it cannot be
	/// move in the global space.
	/// @param j The joint to convert
	/// @param deviceUID The device UID of the joint local space
	Joint inGlobalCoordinates(const Joint &j, const pb::deviceUID deviceUID);

	/// Convert the given vec3 from the local space of the specified device to the global space.
	/// If no layout is loaded or if the specified device is associated with no logical device, this method will return a zero-value vec3
	/// @param local The vec3 in local coordinates
	/// @param deviceUID The device localizing the given vec3
	maths::vec3 inGlobalCoordinates(const maths::vec3 &local, const pb::deviceUID deviceUID);

private:

	/// The save path where to find layouts
	fs::path _savePath;

	/// The currently opened layout, nullptr if no layout is opened
	layout::Layout * _activeLayout = nullptr;

	inline std::string layoutPathFromName(const std::string &name) {
		return _savePath.string() + name + LAYOUT_EXT;
	}

};

} /* ::master */
} /* ::pb */

#endif /* LayoutEngine_hpp */
