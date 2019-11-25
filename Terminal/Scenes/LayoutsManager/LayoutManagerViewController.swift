//
//  LayoutListViewController.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-10-29.
//

import AppKit
import SwiftProtobuf

class LayoutManagerViewController: NSViewController {

	@IBOutlet weak var cancelButton: NSButton!

	@IBOutlet weak var openButton: NSButton!

	@IBOutlet weak var createButton: NSButton!

	@IBOutlet weak var deleteButton: NSButton!

	@IBOutlet weak var layoutsTable: NSTableView!

	private var layoutsList = [String]()

	@IBOutlet weak var progressIndicator: NSProgressIndicator!

	private var subController: NSViewController?

	override func viewDidAppear() {
		super.viewDidAppear()

		layoutsTable.dataSource = self;
		layoutsTable.delegate = self;
	}

	func set(list: Pb_Network_Messages_LayoutList) {
		layoutsList.removeAll()

		layoutsList = list.layoutName.sorted(by: { $0 < $1 })

		layoutsTable?.reloadData()
	}

	@IBAction func openNewLayoutDialog(_ sender: Any) {
		performSegue(withIdentifier: "newLayoutSegue", sender: nil);
	}

	@IBAction func deleteLayout(_ sender: Any) {
		performSegue(withIdentifier: "deleteLayoutSegue", sender: nil)
	}

	@IBAction func openLayout(_ sender: Any) {
		let layoutName = layoutsList[layoutsTable.selectedRow]

		// Lock interface
		cancelButton.isEnabled = false
		openButton.isEnabled = false
		createButton.isEnabled = false
		deleteButton.isEnabled = false
		layoutsTable.isEnabled = false

		progressIndicator.startAnimation(sender)

		Log.info("Opening layout \(layoutName)...")
		App.networkEngine.master.openLayout(withName: layoutName);
	}


	override func prepare(for segue: NSStoryboardSegue, sender: Any?) {
		subController = segue.destinationController as? NSViewController

		if segue.identifier == "deleteLayoutSegue" {
			(subController as! DeleteLayoutViewController).layoutName = layoutsList[layoutsTable.selectedRow]
		}
	}
}

extension LayoutManagerViewController: NSTableViewDataSource {
	func numberOfRows(in tableView: NSTableView) -> Int {
		return layoutsList.count
	}

	func tableView(_ tableView: NSTableView, objectValueFor tableColumn: NSTableColumn?, row: Int) -> Any? {
		return layoutsList[row]
	}
}

extension LayoutManagerViewController: NSTableViewDelegate {
	func tableView(_ tableView: NSTableView, viewFor tableColumn: NSTableColumn?, row: Int) -> NSView? {
		let cell = layoutsTable.makeView(withIdentifier: NSUserInterfaceItemIdentifier(rawValue: "layoutCell"), owner: self) as! NSTableCellView
		cell.textField?.stringValue = layoutsList[row]

		return cell
	}

	func tableViewSelectionDidChange(_ notification: Notification) {
		openButton.isEnabled = layoutsTable.selectedRow > -1
		deleteButton.isEnabled = layoutsTable.selectedRow > -1
	}
}
