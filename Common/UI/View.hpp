//
//  View.hpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-02-27.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef PBView_hpp
#define PBView_hpp

#include <vector>

#include "UI.hpp"

namespace ui {

/** Forward declarations */
class Scene;
class PBControl;

class View {
public:
    View() {};

    View(const PBPoint &aPosition): _frame(PBFrame(aPosition, 0, 0)) {}

    View(const PBFrame &aFrame): _frame(aFrame) {}

    /**
     Gives the local position of the view

     @return The view local position
     */
    inline PBFrame getFrame() { return _frame; }

    /**
     Sets the local frame of the view, effectively updating its position

     @param frame The view local frane
     */
    inline void setFrame(const PBFrame &frame) { _frame = frame; }

    /**
     Update the view local position

     @param position The new position
     */
    inline void setPosition(const PBPoint &position) {
        _frame.x = position.x;
        _frame.y = position.y;
    }

    /** Tell if the view should be omitted when rendering occurs. */
    bool isHidden = false;

    /**
     Tell the view to render itself and its subviews on the screen.
     Views are rendered in the same order they were added, with the current view
     beeing the first.
     */
    virtual void render();

    /**
     Add a child view to this view

     @param view The view to add as a child
     */
    void addSubview(View * view);

    /**
     Remove the current view from its parent view, this does not free the view
     */
    void removeFromSuperView();

    /**
     Gives the currently selected control element, if any. Might be the view itself
     of a subview.

     @return The selected PBControl
     */
    virtual PBControl * getSelectedControl();

    virtual ~View();

protected:
    /**
     Gives the view position in the window, taking into account its parent view position

     @return The view window
     */
    PBPoint getGlobalPosition();

    /** The view holding this view, might be nil */
    View * _superview = nullptr;

    /** The list of subviews */
    std::vector<View *> _subviews;

    /**
     Remove the given view from the list of subviews. This does not free the view

     @param view The view to remove
     */
    void removeSubview(View * view);

private:
    /**
     The view position in its parent view
     */
    PBFrame _frame = PBFrame(0, 0, 0, 0);
};

} /* ::ui */

#endif /* PBView_hpp */
