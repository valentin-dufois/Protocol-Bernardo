//
//  PBHorizontalLine.cpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-03-01.
//  Copyright © 2019 Prisme. All rights reserved.
//

#include "PBHorizontalLine.hpp"

namespace ui {

PBHorizontalLine::PBHorizontalLine(const PBPoint &aPosition, const uint &aLength):
    View(PBFrame(aPosition, length, 1)),
    length(aLength) {}

void PBHorizontalLine::render() {
    nC::clearStyling();

    PBPoint globalPos = getGlobalPosition();
    nC::hLine(globalPos.x, globalPos.y, length);
}

} /* ::ui */
