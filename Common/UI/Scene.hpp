//
//  Scene.hpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-02-27.
//  Copyright © 2019 Prisme. All rights reserved.
//

#ifndef PBScene_hpp
#define PBScene_hpp

namespace ui {

class View;

/** A Scene is used to display a view on the screen.
 If a view can be contained in another view, a scene is needed to display the root view. A Scene takes care of dispatching user events to the currently selected PBControl.

 You should subclass Scene and use its four events methods: `sceneWillAppear()`, `sceneWillRender()`, `sceneDidRender()`, `sceneWillUnload()` to execute your own code.

 A scene has no render-loop, it is left to the user to implement it. This is made to ensure maximum flexibility fo the user. The `render()` method ttriggers the render of all its view and its subviews in cascade.

 A scene is responsible for the view it is holding, and will free its contained views when being free-ed.

 Interaction between elements of different scenes, and between scenes themselves is undefined behaviour.

 To remove a view, call `dismiss()`, this will remove the view from the render
 loop and free its content.
 */
class Scene {
public:
    /** Create a scene with an empty view */
    Scene();

    /** Create a scene and present the given view
	 
    @param view The view to display
    */
    Scene(View * view);

    /**
     Replace the currently presented view by the given one

     @param view The view to display
     */
    void presentView(View * view);

	/**
	 Render the scene and its content on the screen
	 */
	void render();

    /**
     Gives the view currently presented by this scene

     @return The presented view
     */
    inline View * getView() { return _view; }

    /** This will also free the entire view hierarchy hold by this scene.
     `sceneWillUnload()` is called right before freeing everything.
     */
    virtual ~Scene();

protected:
    /**
     Called when the view was just created, should be used to setup elements of the view.
     */
    virtual void sceneWillAppear();

    /**
     Called everytime the view is about to render, should be used to perform updates
     before rendering. This is called after events have been sent.
     Another scene may have already rendered its content when this method is called
     */
    virtual void sceneWillRender();

    /**
     Called everytime the view just rendered, should be used for post render operation.
     Other scene may still have to render their content
     */
    virtual void sceneDidRender();

    /**
     Called when the scene is about to be freed. This is usually called when the scene is removed from the render loop
     The contained view and its subviews are automatically freed by the scene
     after this method.
     */
    virtual void sceneWillUnload();

private:

    /** The view presented by this scene */
    View * _view;
};

} /* ::ui */

#endif /* PBScene_hpp */
