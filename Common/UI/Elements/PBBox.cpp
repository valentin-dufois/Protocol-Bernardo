//
//  PBBox.cpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-04-15.
//  Copyright © 2019 Prisme. All rights reserved.
//

#include "PBBox.hpp"

namespace ui {

void PBBox::render() {
	PBPoint pos = getGlobalPosition();
	nC::box(pos.x, pos.y, getFrame().width, getFrame().height);

	View::render();
}

} /* ::ui */
