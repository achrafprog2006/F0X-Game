#pragma once

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<vector>
#include<memory>

struct Transform {
   
public:
    glm::vec3 position = glm::vec3(0);
    glm::vec3 rotation = glm::vec3(0);
    float scale = 1;
    glm::mat4 transformationMatrix = glm::mat4(1);

    Transform()=default;
    Transform(const glm::vec3& pos, const glm::vec3& rot,float scale)
        :position(pos),
         rotation(rot),
         scale(scale)
    {
        transformationMatrix = glm::translate(glm::mat4(1.0f), position);
        transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
        transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
        transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));
        transformationMatrix = glm::scale(transformationMatrix, glm::vec3(scale, scale, scale));
    }
};