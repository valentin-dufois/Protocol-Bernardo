//
//  PBBox.hpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-04-15.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef PBBox_hpp
#define PBBox_hpp

#include "../View.hpp"
#include "../utils/PBPoint.hpp"

namespace ui {

class PBBox: public View {
public:
	PBBox(const PBPoint &aPosition): View(PBFrame(aPosition, 1, 1)) {}

	PBBox(const PBFrame &aFrame): View(aFrame) {}

	void render() override;
};

} /* ::ui */

#endif /* PBBox_hpp */
