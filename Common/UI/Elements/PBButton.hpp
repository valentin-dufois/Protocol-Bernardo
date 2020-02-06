//
//  PBButton.hpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-02-27.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef PBButton_hpp
#define PBButton_hpp

#include "PBControl.hpp"
#include "PBLabel.hpp"

namespace ui {

class PBButton: public PBControl {
public:
    PBButton(const std::string &aTitle, const PBPoint &aPosition);

    /**
     Changes the button's title

     @param title The new title for the button
     */
    inline void setTitle(const std::string &title) { titleLabel->setTitle(title); }

    /**
     Gives the current title of the button

     @return The button title
     */
    inline std::string getTitle() { return titleLabel->getTitle(); }

    bool isInline = false;

    // MARK: - View
    void render() override;
    
private:
    PBLabel * titleLabel;
};

} /* ::ui */

#endif /* PBButton_hpp */
