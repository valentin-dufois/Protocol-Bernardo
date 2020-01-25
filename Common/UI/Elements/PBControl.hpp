//
//  PBControl.hpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-02-27.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef PBControl_hpp
#define PBControl_hpp

#include "../View.hpp"

namespace ui {

class PBControl: virtual public View {
public:
    PBControl() {}

    PBControl(void * aValue): value(aValue) {}

    /** The top neighboor of this control */
    PBControl * topNeighboor = nullptr;

    /** The right neighboor of this control */
    PBControl * rightNeighboor = nullptr;

    /** The bottom neighboor of this control */
    PBControl * bottomNeighboor = nullptr;

    /** The left neighboor of this control */
    PBControl * leftNeighboor = nullptr;
    /**
     Tell if the control is selected

     @return True if selected, false otherwise
     */
    inline bool isSelected() const { return _isSelected; }

    /**
     Tell the control to execute its action
     */
    virtual void onKeyPressed(const std::vector<keyCode> &pressedKeys);

    /**
     Select the control, update its appearance

     @param sender The element the selection is coming from
     */
    virtual void select(PBControl * sender);

    /**
     Deselect the control, change is appearance
     */
    virtual void deselect();

    /** The button's action */
    std::function<void(PBControl *)> action;

    /**
     Change the selection from the current control to the given one

     @param control The next control to select
     */
    void moveToControl(PBControl * control);

    /** The control value */
    void * value = nullptr;

protected:
    /** Tell if the control is currently selected */
    bool _isSelected = false;
};

} /* ::ui */

#endif /* PBControl_hpp */
