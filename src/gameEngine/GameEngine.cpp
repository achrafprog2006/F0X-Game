#include"GameEngine.h"

#include<glad/glad.h>
#include "../screen/Screen.h"
#include"../entities/Camera.h"
#include <iostream>
#include<memory>

GameEngine::GameEngine()
{}


void GameEngine::run()
{
    auto  screen=std::make_shared<Screen>(800, 600, "LearnOpenGL");
    auto camera = std::make_shared<Camera>();
    screen->init();
    float red=0;
    while (screen->is_open())
    {
        glClearColor(0, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        screen->update(camera);
    }
    
}

 