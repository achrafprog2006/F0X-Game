#pragma once
#include"../screen/Screen.h"
#include"../scenes/Scene1.h"
#include<memory>

class GameEngine{

public:
    std::shared_ptr<Screen> screen;
    std::shared_ptr<Scene1> scene;
	bool running = false;
    GameEngine();
    void run();

};