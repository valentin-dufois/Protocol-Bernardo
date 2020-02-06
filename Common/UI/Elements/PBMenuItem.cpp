//
//  PBMenuItem.cpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-02-27.
//  Copyright © 2019 Prisme. All rights reserved.
//

#include "PBMenuItem.hpp"

namespace ui {

PBMenuItem::PBMenuItem(const std::string &aTitle):
    PBMenuItem(aTitle, nullptr) {}

PBMenuItem::PBMenuItem(const std::string &aTitle, void * aValue):
    View(PBFrame(0, 0, uint(aTitle.size()), 1)),
    PBControl(aValue),
    titleLabel(new PBLabel(aTitle, PBPoint(0, 0))) {
    addSubview(titleLabel);
}

void PBMenuItem::render() {
    nC::clearStyling();

    if (isSelected()) {
        nC::setBold();
    }

    titleLabel->renderWithoutStyling();
}

} /* ::ui */
