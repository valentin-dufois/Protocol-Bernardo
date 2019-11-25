//
//  ViewController.swift
//  pb-terminal
//
//  Created by Valentin Dufois on 2019-09-17.
//

import AppKit

class MainViewController: NSViewController {

	weak var layoutManagerController: LayoutManagerViewController?

	weak var layoutInterfaceController: LayoutCanvasViewController?

	@IBOutlet weak var welcomeView: NSView!

	@IBOutlet weak var loadingIndicator: NSProgressIndicator!

	@IBOutlet weak var containerView: NSView!

	override func viewDidLoad() {
		super.viewDidLoad()
	}

	override func viewDidAppear() {
		super.viewDidAppear();

		containerView?.isHidden = true;
		loadingIndicator?.startAnimation(nil);
	}

	override func prepare(for segue: NSStoryboardSegue, sender: Any?) {
		switch segue.identifier {
		case "layoutListSegue":
			layoutManagerController = segue.destinationController as? LayoutManagerViewController
			layoutManagerController?.set(list: sender as! Pb_Network_Messages_LayoutList)
		case "layoutInterfaceSegue":
			layoutInterfaceController = segue.destinationController as? LayoutCanvasViewController
		default:
			return
		}
	}

	func showWelcomeView() {
		welcomeView?.isHidden = false;
		containerView?.isHidden = true;

		layoutInterfaceController?.clear();

		layoutManagerController?.dismiss(nil);
		layoutInterfaceController?.dismiss(nil);
	}

	func showLayoutInterface() {
		welcomeView?.isHidden = true;
		containerView?.isHidden = false;

		Log.info("\(App.layoutEngine.layout.name) opened")
	}

	func closeLayoutsList() {
		layoutManagerController?.dismiss(nil);
	}

	func closeLayoutInterface() {
		layoutInterfaceController?.dismiss(nil);
	}
}
