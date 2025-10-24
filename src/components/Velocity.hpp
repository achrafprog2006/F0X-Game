#pragma once

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<vector>
#include<memory>

struct Velocity {

public:
    glm::vec3 velocity = glm::vec3(0.0f);

    Velocity() = default;
    Velocity(const glm::vec3& velocity)
        :velocity(velocity)
    {
    }

};