#pragma once

#include <vector>
#include <memory>
#include <glm/glm.hpp>

struct Terrain {
public:
    std::vector<std::vector<float>> heightData;
    int size = 1000;
    float spacing = 1.0f;
    glm::vec3 origin = glm::vec3(0.0f);

    Terrain() = default;

    
};
