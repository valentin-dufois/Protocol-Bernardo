//
//  CanvasElementViewController.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-11-03.
//

import AppKit

class CanvasPropertiesViewController: NSViewController {

	@IBOutlet weak var parametersTable: NSTableView!

	weak var viewLeadingConstraint: NSLayoutConstraint!

	var parametersViews = [CanvasProperty]()

	func showParameters(_ views: [CanvasProperty]) {
		view.isHidden = false
		NSAnimationContext.runAnimationGroup({ _ in
			NSAnimationContext.current.duration = 0.15
			view.animator().alphaValue = 1.0
//			viewLeadingConstraint.animator().constant = 0;
		})

		parametersViews = views;
		parametersTable.reloadData()
	}

	func hideParameters() {
		NSAnimationContext.runAnimationGroup({ _ in
			NSAnimationContext.current.duration = 0.15
			view.animator().alphaValue = 0.0
//			viewLeadingConstraint.animator().constant = -100;
		}, completionHandler:{
			self.view.isHidden = true
		})

		parametersViews = []
	}
}

extension CanvasPropertiesViewController: NSTableViewDataSource {
	func numberOfRows(in tableView: NSTableView) -> Int {
		return parametersViews.count
	}

	func tableView(_ tableView: NSTableView, objectValueFor tableColumn: NSTableColumn?, row: Int) -> Any? {
		return row
	}
}

extension CanvasPropertiesViewController: NSTableViewDelegate {
	func tableView(_ tableView: NSTableView, viewFor tableColumn: NSTableColumn?, row: Int) -> NSView? {
		return parametersViews[row];
	}

	func tableView(_ tableView: NSTableView, heightOfRow row: Int) -> CGFloat {
		return CGFloat(parametersViews[row].displayHeight)
	}

	func tableView(_ tableView: NSTableView, shouldSelectRow row: Int) -> Bool {
		return false
	}
}

