//
//  PBVerticalLine.cpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-03-02.
//  Copyright © 2019 Prisme. All rights reserved.
//

#include "PBVerticalLine.hpp"

namespace ui {

PBVerticalLine::PBVerticalLine(const PBPoint &aPosition, const uint &aLength):
View(PBFrame(aPosition, length, 1)),
length(aLength) {}

void PBVerticalLine::render() {
    nC::clearStyling();
    
    PBPoint globalPos = getGlobalPosition();
    nC::vLine(globalPos.x, globalPos.y, length);
}

} /* ::ui */
