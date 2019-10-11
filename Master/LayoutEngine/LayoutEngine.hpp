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

namespace fs = std::filesystem;
namespace layout {
class Layout;
}

class LayoutEngine {
public:
	LayoutEngine();

	std::vector<std::string> getLayouts();

	layout::Layout * createLayout(const std::string &name);

	layout::Layout * openLayout(const std::string &name);

	void renameLayout(const std::string &newName);

	void updateLayout(layout::Layout * layout);

	void closeLayout();

	std::vector<std::string> deleteLayout(const std::string &name);

private:

	fs::path _savePath;

	layout::Layout * _openedLayout = nullptr;

};

#endif /* LayoutEngine_hpp */
