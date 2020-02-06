//
//  PBControl.cpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-02-27.
//  Copyright © 2019 Prisme. All rights reserved.
//

#include "PBControl.hpp"

namespace ui {

void PBControl::onKeyPressed(const std::vector<keyCode> &pressedKeys) {
    for(keyCode key: pressedKeys) {
        switch(key) {
            case KEY_UP:
                moveToControl(topNeighboor);
                return;
            break;
            case KEY_RIGHT:
                moveToControl(rightNeighboor);
                return;
            case KEY_DOWN:
                moveToControl(bottomNeighboor);
                return;
            case KEY_LEFT:
                moveToControl(leftNeighboor);
                return;
            case 10:
                action(this);
            break;
            default:
                return;
        }
    }
}

void PBControl::select(PBControl * sender) {
    _isSelected = true;
}

void PBControl::deselect() {
    _isSelected = false;
}

void PBControl::moveToControl(PBControl * control) {
    if(control != nullptr) {
        deselect();
        control->select(this);
    }
}

} /* ::ui */
