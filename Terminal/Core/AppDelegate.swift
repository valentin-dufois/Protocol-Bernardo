//
//  AppDelegate.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-09-17.
//

import Cocoa

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {

	func applicationDidFinishLaunching(_ aNotification: Notification) {
		App.networkEngine.start()
		App.networkEngine.delegate = self
	}

	func applicationWillTerminate(_ aNotification: Notification) {
		// Insert code here to tear down your application
	}


	private var _browser: Browser?

	/// Update the status bar label with the given one
	/// - Parameter status: The new status updatet
	func pushStatus(_ status: String) {
		App.mainWindow?.statusBar.setLabel(status, forSegment: 0)
	}
}

extension AppDelegate {
	@IBAction func onMenuOpen(_ sender: Any) {
		App.networkEngine.requestLayoutList()
	}

	@IBAction func onMenuClose(_ sender: Any) {

	}

	@IBAction func onMenuSave(_ sender: Any) {
		App.layoutEngine.save()
	}

	@IBAction func onMenuRevertToSave(_ sender: Any) {
		
	}

	@IBAction func onMenuResetLayoutCanvasViewport(_ sender: Any) {
		NotificationCenter.default.post(name: NSNotification.Name("layoutCanvasResetViewport"), object: nil);
	}
}

extension AppDelegate: NetworkEngineDelegate {
	func onReceive(status: Messages_MasterStatus) {
		if App.isStarting {
			if status.activeLayout.count == 0 {
				Log.info("Requesting layout list...");
				App.networkEngine.requestLayoutList();
			} else {
				Log.info("Requesting active layout...");
				App.networkEngine.requestLayout(name: status.activeLayout);
			}
			App.isStarting = false;
		}
	}

	func onReceive(layoutList: Messages_LayoutList) {
		App.mainWindow?.showLayoutList(layoutList)
	}

	func onReceive(layout: Messages_Layout) {
		// Open event.
		// Close the layout list if needed
		App.mainWindow?.closeLayoutList()
		App.mainWindow?.closeLayoutInterface()

		App.layoutEngine.setLayout(layout);
	}

	func onReceive(trackedBodies: Messages_TrackedBodies) {
		App.mainWindow?.showTrackedBodies(trackedBodies);
	}
}
