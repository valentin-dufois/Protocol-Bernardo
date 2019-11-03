//
//  Comparable.swift
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-01-29.
//  Copyright © 2019 Prisme. All rights reserved.
//

import Foundation

extension Comparable {
    /// Clamp the value inside the given range
    ///
    /// - Parameter r: The limit range
    /// - Returns: The value clamped to the range
    func clamped(to r: ClosedRange<Self>) -> Self {
        let min = r.lowerBound, max = r.upperBound
        return self < min ? min : (max < self ? max : self)
    }
}
