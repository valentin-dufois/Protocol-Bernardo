//
//  PBHorizontalLine.hpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-03-01.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef PBHorizontalLine_hpp
#define PBHorizontalLine_hpp

#include "../View.hpp"
#include "../utils/PBPoint.hpp"

namespace ui {

class PBHorizontalLine: public View {
public:
    PBHorizontalLine(const PBPoint &aPosition, const uint &aLength);

    uint length;

    // MARK: - View
    void render();
};

} /* ::ui */

#endif /* PBHorizontalLine_hpp */
