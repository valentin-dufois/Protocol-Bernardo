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

#include "../../Common/Utils/Log.hpp"

#define LAYOUT_EXT ".pblayout"

namespace fs = std::filesystem;
namespace layout {
class Layout;
}

class LayoutEngine {
public:
	LayoutEngine();

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

	/// Tell if there is a layout open
	inline bool hasActiveLayout() { return _activeLayout != nullptr; }

	/// Gives the currently active layout, Returns nullptr if no layou is open
	inline layout::Layout * activeLayout() { return _activeLayout; }

	/// Close the currently opened layout
	void closeLayout();


	/// Delete the specified layout
	/// @param name Name of the layout to delete
	/// @returns The updated list of available layouts
	std::vector<std::string> deleteLayout(const std::string &name);

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
