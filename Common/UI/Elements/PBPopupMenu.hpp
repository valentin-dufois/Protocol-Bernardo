//
//  PBPopupMenu.hpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-02-27.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef PBPopupMenu_hpp
#define PBPopupMenu_hpp

#include "PBButton.hpp"

namespace ui {

/** Forward declaration */
class PBMenuItem;

/**
 Represent a popup menu allowing the user to select an item from of list when opened
 */
class PBPopupMenu: public PBButton {
public:
    /**
     Add a new item at the end of the menu with the given title, and holding
     the given value

     @param title Title of the item, will be displayed
     @param value Value of the item, to retrieve later
     */
    void addItem(const std::string &title, const void * value);

    /**
     Clears the menu
     */
    void removeAllItems();

    /**
     Gives the title of the selected item, if no item is selected, this returns
     the popup menu title

     @return The title of the selected item
     */
    std::string titleOfSelectedItem();

    /**
     Gives the value of the selected item, the value may be nullptr if no value
     was given or if no item is selected

     @return The value of the selected item
     */
    void * valueOfSelectedItem();

    // MARK: - PBButton

    void click();

    /** PopupMenu's action */
    std::function<void(PBPopupMenu *)> action;

    // MARK: - View

    void render();

protected:
    /** The list of items in the menu */
    std::vector<PBMenuItem *> _items;

    /** Index of the currently selected item */
    int selectedItem = -1;

    void onItemSelected(PBMenuItem *);
};

} /* ::ui */

#endif /* PBPopupMenu_hpp */
