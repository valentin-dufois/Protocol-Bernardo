//
//  PBLabel.cpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-02-27.
//  Copyright © 2019 Prisme. All rights reserved.
//

#include "PBLabel.hpp"

namespace ui {

PBLabel::PBLabel(const std::string &aTitle, const PBPoint &aPosition):
    View(PBFrame(aPosition, uint(aTitle.size()), 1)),
    _title(aTitle) {}

void PBLabel::renderWithoutStyling() {
    PBPoint globalPos = getGlobalPosition();
    int posX = globalPos.x;
    int posY = globalPos.y;

    // Adjust the label position based on its alignement
    switch(alignement) {
        case LABEL_ALIGN_LEFT: break;
        case LABEL_ALIGN_CENTER: posX -= (_title.size() / 2); break;
        case LABEL_ALIGN_RIGHT: posX -= _title.size(); break;
    }

    if(isBold) { nC::setBold(); }
    if(isUnderlined) { nC::setUnderline(); }

    nC::print << nC::mv(posX, posY) << _title;
}

void PBLabel::render() {
    nC::clearStyling();

    renderWithoutStyling();
}

} /* ::ui */
