//
//  PBVerticalMenu.cpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-03-01.
//  Copyright © 2019 Prisme. All rights reserved.
//

#include "PBVerticalMenu.hpp"
#include "PBMenuItem.hpp"

#include <string>

namespace ui {

PBVerticalMenu::PBVerticalMenu(const PBPoint &aPosition):
    View(aPosition) {}

void PBVerticalMenu::addItem(const std::string &title, const std::function<void(PBMenuItem *)> action, void * value) {
    PBMenuItem * item = new PBMenuItem(title, value);
    item->action = action;

    addItem(item);
}

void PBVerticalMenu::addItem(PBMenuItem * item) {
    item->leftNeighboor = leftNeighboor;
    item->rightNeighboor = rightNeighboor;
    item->bottomNeighboor = bottomNeighboor;

    item->topNeighboor = _items.size() == 0 ? topNeighboor : _items[_items.size() - 1];

    if(_items.size() > 0) {
        _items[_items.size() - 1]->bottomNeighboor = item;
    } else {
        _selectedItem = item;
    }

    PBFrame itemFrame = item->getFrame();
    itemFrame.x = 2;
    itemFrame.y = uint(_items.size());

    item->setFrame(itemFrame);

    _items.push_back(item);
    addSubview(item);
}

void PBVerticalMenu::removeItem(PBMenuItem * item) {
    if(item->isSelected()) {
        item->moveToControl(item->topNeighboor);
    }

    _items.erase(std::remove(_items.begin(), _items.end(), item));
    item->removeFromSuperView();
    delete item;
}

void PBVerticalMenu::removeAllItems() {
    for(PBMenuItem * item: _items) {
        removeItem(item);
    }
}

void PBVerticalMenu::selectItem(PBMenuItem * item) {
    if(_selectedItem != nullptr) {
        _selectedItem = nullptr;
    }

    ptrdiff_t pos = std::find(_items.begin(), _items.end(), item) - _items.begin();

    if(pos < _items.size()) {
        _selectedItem = item;
        _selectedIndex = uint(pos);
    }
}

void PBVerticalMenu::select(PBControl * sender) {
    PBControl::select(sender);

    unsigned long itemsCount = getItemsCount();

    if(itemsCount > 0) {
        return;
    }

    // If the menu is empty, selection pass through the menu
    if(sender->bottomNeighboor == this) {
        // Going down
        moveToControl(bottomNeighboor);
    }

    if(sender->leftNeighboor == this) {
        // Going left
        moveToControl(leftNeighboor);
    }

    if(sender->topNeighboor == this) {
        // Going top
        moveToControl(topNeighboor);
    }

    if(sender->rightNeighboor == this) {
        // Going right
        moveToControl(rightNeighboor);
    }

    if(isSelected()) {
        // Could not select another neighboor, keep the selection on the sender
        moveToControl(sender);
    }
}

void PBVerticalMenu::onKeyPressed(const std::vector<keyCode> &pressedKeys) {
    for(keyCode key: pressedKeys) {
        switch(key) {
            case KEY_RIGHT: return moveToControl(rightNeighboor);
            case KEY_LEFT: return moveToControl(leftNeighboor);
            case 10: _selectedItem->action(_selectedItem); break;
            case KEY_UP:
                if(_selectedIndex == 0) {
                    return moveToControl(topNeighboor);
                }

                return selectItem(_items[_selectedIndex-1]);
            case KEY_DOWN:
                if(_selectedIndex == _items.size() - 1) {
                    return moveToControl(bottomNeighboor);
                }

                return selectItem(_items[_selectedIndex + 1]);
            default: return;
        }
    }
}

void PBVerticalMenu::render() {
    PBPoint pos = getGlobalPosition();

    // Clear cursor area
    nC::clearArea(pos.x, pos.y, 2, uint(_items.size()));

    // Rendre the items
    View::render();

    if(getItemsCount() == 0) {
        nC::print << nC::mv(pos.x + 2, pos.y) << emptyMessage;
    }

    if(!_isSelected) { return; }

    // display the cursor
    nC::print << nC::mv(pos.x, pos.y + _selectedIndex) << u8"→";
}

PBControl * PBVerticalMenu::getSelectedControl() {
    return _selectedItem == nullptr ? nullptr : this;
}

} /* ::ui */
