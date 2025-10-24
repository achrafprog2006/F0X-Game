#include "Camera.h"
#include<iostream>
#include"../screen/Screen.h"

void Camera::updateViewMatrix()
{
    viewMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(-rotation.x), glm::vec3(1, 0, 0));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(-rotation.y), glm::vec3(0, 1, 0));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(-rotation.z), glm::vec3(0, 0, 1));
    viewMatrix = glm::translate(viewMatrix, -position);

}



void Camera::updateProjectionMatrix(float SC_width, float SC_height)
{
    float aspectRatio = SC_width /SC_height;
    projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, near, far);
}


Camera::Camera(const glm::vec3& pos, const glm::vec3& rot,float SC_width, float SC_height)
    :position(pos),
     rotation(rot)
{
    updateViewMatrix();
    updateProjectionMatrix(SC_width, SC_height);
    // transformationMatrix = glm::scale(transformationMatrix, glm::vec3(scale, scale, scale));
}
void Camera::setRotation(const glm::vec3& rot)
{
    rotation = rot;
    updateViewMatrix();

}


void Camera::setPosition(const glm::vec3& pos)
{
    position = pos;
    updateViewMatrix();
}

void Camera::translate(const glm::vec3& t)
{
    position += t;
    updateViewMatrix();
}
void Camera::rotate(const glm::vec3& r)
{
    rotation += r;
    updateViewMatrix();
}

const  glm::mat4& Camera::getViewMatrix()const
{
    return viewMatrix;
}
const  glm::mat4& Camera::getProjectionMatrix()const
{
    return projectionMatrix;
}
