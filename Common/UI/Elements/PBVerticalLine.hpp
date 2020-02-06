//
//  PBVerticalLine.hpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-03-02.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef PBVerticalLine_hpp
#define PBVerticalLine_hpp

#include "../View.hpp"
#include "../utils/PBPoint.hpp"

namespace ui {

class PBVerticalLine: public View {
public:
    PBVerticalLine(const PBPoint &aPosition, const uint &aLength);

    uint length;

    // MARK: - View
    void render();
};

} /* ::ui */

#endif /* PBVerticalLine_hpp */
