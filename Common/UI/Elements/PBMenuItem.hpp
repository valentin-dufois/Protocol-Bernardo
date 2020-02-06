//
//  PBMenuItem.hpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-02-27.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef PBMenuItem_hpp
#define PBMenuItem_hpp

#include "../UI.hpp"
#include "PBControl.hpp"
#include "PBLabel.hpp"

namespace ui {

class PBMenuItem: virtual public PBControl {
public:
    PBMenuItem(const std::string &aTitle);

    PBMenuItem(const std::string &aTitle, void * aValue);

    /**
     Changes the menu item's title

     @param title The new title for the button
     */
    inline void setTitle(const std::string &title) { titleLabel->setTitle(title); }

    /**
     Gives the current title of the menu item

     @return The button title
     */
    inline std::string getTitle() { return titleLabel->getTitle(); }

    // MARK: - PBControl

    /** The button's action */
    std::function<void(PBMenuItem *)> action;


    // MARK: - View
    void render() override;

private:
    PBLabel * titleLabel;
};

} /* ::ui */

#endif /* PBMenuItem_hpp */
