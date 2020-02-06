//
//  PBFrame.hpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-02-27.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef PBFrame_hpp
#define PBFrame_hpp

#include "../UI.hpp"

namespace ui {

struct PBFrame {
    int x;
    int y;

    uint width;
    uint height;

    PBFrame(const int &x, const int &y, const uint &aWidth, const uint &aHeight):
        x(x),
        y(y),
        width(aWidth),
        height(aHeight) {}

    PBFrame(const PBPoint &aPoint, const uint &aWidth, const uint &aHeight):
        x(aPoint.x),
        y(aPoint.y),
        width(aWidth),
        height(aHeight) {}

    PBPoint getPosition() {
        return PBPoint(x, y);
    }

    PBPoint getSize() {
        return PBPoint(width, height);
    }

    /**
     Gives a frame representing the current frame containing the given frame

     @param b The frame contained by the current one
     @return A Frame containing the both frames
     */
    PBFrame operator >>(const PBFrame &b) {
        PBFrame frame(0, 0, 0, 0);
        frame.x = b.x < 0 ? x + b.x : x;
        frame.y = b.y < 0 ? y + b.y : y;

        frame.width = (b.width + b.x) > width ? (b.width + b.x) : width;
        frame.height = (b.height + b.y) > height ? (b.height + b.y) : height;

        return frame;
    }
};

} /* ::ui */

#endif /* PBFrame_hpp */
