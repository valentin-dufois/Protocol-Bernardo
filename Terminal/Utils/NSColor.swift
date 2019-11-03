//
//  NSColor.swift
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-01-28.
//  Copyright © 2019 Prisme. All rights reserved.
//

import AppKit

extension NSColor {
    convenience init(_ nsColor: NSColor, alpha: CGFloat) {
        let color = nsColor.usingColorSpace(NSColorSpace.deviceRGB)!
        self.init(red: color.redComponent,
                     green: color.greenComponent,
                     blue: color.blueComponent,
                     alpha: alpha)
    }
}
