//
//  PBPoint.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-02-27.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef PBPoint_hpp
#define PBPoint_hpp

#include "../UI.hpp"

namespace ui {

struct PBPoint {
    int x;
    int y;

    PBPoint(const int &aX, const int &aY): x(aX), y(aY) { }

    PBPoint operator +(const PBPoint &right) {
        return PBPoint(x + right.x, y + right.y);
    }
};

} /* ::ui */

#endif /* PBPoint_hpp */
