//
//  NSNib.swift
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-01-27.
//  Copyright © 2019 Prisme. All rights reserved.
//

import AppKit

extension NSNib {
    /// Instanciate the view/window of the method type from the specified Nib
    ///
    /// - Parameters:
    ///   - nibName: Name of the nib to extract the view/window fron
    ///   - owner: _
    /// - Returns: The instanciated view/window
    static func make<T>(fromNib nibName: String, owner: AnyObject?) -> T {
        var instanciatedViews: NSArray? = []
        
        // Instanciate the views
        guard Bundle.main.loadNibNamed(nibName, owner: owner, topLevelObjects: &instanciatedViews), let objects = instanciatedViews else {
            fatalError("Could not load view from nib file \(nibName)")
        }
        
        // Filter for the correct type of view
        let views = objects.filter { $0 is T }
        
        guard views.count == 1 else {
            fatalError("Could not extract the view from the nib. (Number of view with the correct type found : \(views.count)")
        }

        guard let view = views.first as? T else {
            fatalError()
        }
        
        return view
    }
}
