#pragma once

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/glm.hpp>
#include<vector>
#include<memory>

class Camera
{
public:

    glm::vec3 position;
    glm::vec3 rotation;
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;
    float near = 1
        , far = 700
        , fov = 45;

    Camera(const glm::vec3& pos, const glm::vec3& rot, float SC_width, float SC_height);
    void translate(const glm::vec3& t);
    void setPosition(const glm::vec3& pos);
    void setRotation(const glm::vec3& rot);
    void rotate(const glm::vec3& r);
    void updateViewMatrix();
    void updateProjectionMatrix(float SC_width, float SC_height);

    const  glm::mat4& getViewMatrix()const;
    const  glm::mat4& getProjectionMatrix()const;




};
