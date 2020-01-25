//
//  Scene.cpp
//  Protocol Bernardo Slave
//
//  Created by Valentin Dufois on 2019-02-27.
//  Copyright © 2019 Prisme. All rights reserved.
//

#include "Scene.hpp"
#include "View.hpp"

namespace ui {

Scene::Scene(): Scene(new View()) {}

Scene::Scene(View * aView):
    _view(aView) {}

void Scene::render() {
    sceneWillRender();

    _view->render();

    sceneDidRender();
}

Scene::~Scene() {
    sceneWillUnload();

    delete _view;
}

void Scene::sceneWillAppear() {}

void Scene::sceneWillRender() {}

void Scene::sceneDidRender() {}

void Scene::sceneWillUnload() {}

} /* ::ui */
