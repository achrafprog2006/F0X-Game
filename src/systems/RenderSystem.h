#pragma once


#include<memory>
#include<vector>
#include"../entities/Entity.h"

namespace RenderSystem {

    void init();
    void render(const std::shared_ptr<Entity>& entity);
    void render(const std::vector<std::shared_ptr<Entity>>& entities);
    void cleanup();

};

