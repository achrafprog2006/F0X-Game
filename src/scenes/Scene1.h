#pragma once
#include<memory>

#include"../screen/Screen.h"
#include"../entities/EntityManager.h"
#include"../entities/Camera.h"

class Scene1 {
 
public:
    bool active = true;
    std::unique_ptr<EntityManager> entityManager;
    std::shared_ptr<Screen> screen;
    std::shared_ptr<Camera> camera;


    Scene1( std::shared_ptr<Screen>& scr);
    Scene1() =default;
    ~Scene1();               
     void init();          
     void update();   
     void upload_Shader_Data();
     void hundle_input();

   
};
