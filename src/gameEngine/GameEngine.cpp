#include"GameEngine.h"
#include"../entities/Camera.h"
#include <iostream>
#include"../scenes/Scene1.h"


GameEngine::GameEngine()
{}


void GameEngine::run()
{
    screen = std::make_shared<Screen>(800, 600, "Salam o alaykom");
	running = screen->init();
    scene = std::make_shared<Scene1>(screen);
    scene->init();
    while (screen->is_open()&& running)
    {
        screen->update(scene->camera);
        scene->update();
    }
}

 