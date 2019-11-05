//
//  LayoutEngine.hpp
//  pb-acquisitor
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
#include "../../Common/Utils/Log.hpp"
#include "../../Common/Utils/maths.hpp"

#define LAYOUT_EXT ".pblayout"

namespace fs = std::filesystem;
namespace layout {
class Layout;
class Device;
}

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

	/// Convert the given vec3 from the local space of the specified device to the global space.
	/// If no layout is loaded or if the specified device is associated with no logical device, this method will return a zero-value vec3
	/// @param local The vec3 in local coordinates
	/// @param deviceUID The device localizing the given vec3
	vec3 globalCoordinates(const vec3 &local, const pb::deviceUID deviceUID);

private:

	/// The save path where to find layouts
	fs::path _savePath;

	/// The currently opened layout, nullptr if no layout is opened
	layout::Layout * _activeLayout = nullptr;

	inline std::string layoutPathFromName(const std::string &name) {
		return _savePath.string() + name + LAYOUT_EXT;
	}

};

#endif /* LayoutEngine_hpp */
