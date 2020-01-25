//
//  PBVerticalMenu.hpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-03-01.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef PBVerticalMenu_hpp
#define PBVerticalMenu_hpp

#include "../UI.hpp"
#include "PBControl.hpp"

namespace ui {

/** Forward declarations */
class PBMenuItem;

class PBVerticalMenu: public PBControl {
public:
    PBVerticalMenu(const PBPoint &aPosition);

    /**
     Add a new item at the end of the menu with the given title, and holding
     the given value

     @param title Title of the item, will be displayed
     @param action Action of the item, called when th user pressed enter on it
     @param value Value of the item, to retrieve later
     */
    void addItem(const std::string &title, const std::function<void(PBMenuItem *)> action, void * value = nullptr);

    /**
     Insert the item at the end of the menu

     @param item The item to add
     */
    void addItem(PBMenuItem * item);

    std::string emptyMessage = "Menu is empty";

    /**
     Tell the number of item in the list

     @return The number of items in the list
     */
    inline unsigned long getItemsCount() { return _items.size(); }

    /**
     Gets the item matching the given index. The given index must be in the array
     or this will crash.

     @param index Index of the item
     @return Item at the given index
     */
    inline PBMenuItem * getItem(const int &index) { return _items[index]; }

    /**
     Removes the given item from the menu

     @param item The item to remove
     */
    void removeItem(PBMenuItem * item);

    /**
     Removes all the items fromn the menu
     */
    void removeAllItems();

    /**
     Select the specified item from the menu

     @param item The item to select
     */
    void selectItem(PBMenuItem * item);

    // MARK: - PBControl

    void select(PBControl * sender) override;

    void onKeyPressed(const std::vector<keyCode> &pressedKeys) override;

    // MARK: - View

    void render() override;

    PBControl * getSelectedControl() override;

protected:
    std::vector<PBMenuItem *> _items = std::vector<PBMenuItem *>();

    PBMenuItem * _selectedItem;
    uint _selectedIndex = 0;
};

} /* ::ui */

#endif /* PBVerticalMenu_hpp */
