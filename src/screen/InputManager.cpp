#include "InputManager.h"
#include<iostream>

InputManager::InputManager(GLFWwindow* win) : window(win) {}

void InputManager::update()
{
    // Update keys
    for (auto& [key, wasDown] : keyDown)
    {
        bool isDown = glfwGetKey(window, key) == GLFW_PRESS;
        keyDown[key] = isDown;
    }

    // Update mouse buttons
    for (auto& [button, wasDown] : mouseDown)
    {
        bool isDown = glfwGetMouseButton(window, button) == GLFW_PRESS;
        mouseDown[button] = isDown;
    }
}

bool InputManager::isKeyPressed(int key)
{
    return glfwGetKey(window, key) == GLFW_PRESS;
}

bool InputManager::isKeyJustPressed(int key)
{
    bool current = glfwGetKey(window, key) == GLFW_PRESS;
    bool& previous = keyDown[key];
    bool justPressed = current && !previous;
    previous = current;
    return justPressed;
}

bool InputManager::isMousePressed(int button)
{
    return glfwGetMouseButton(window, button) == GLFW_PRESS;
}

bool InputManager::isMouseJustPressed(int button) 
{
    bool current = glfwGetMouseButton(window, button) == GLFW_PRESS;
    bool& previous = mouseDown[button];
    bool justPressed = current && !previous;
    previous = current;
    return justPressed;
}

double InputManager::getMouseX() const 
{
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    return x;
}

double InputManager::getMouseY() const
{
    double x, y;
    glfwGetCursorPos(window, &x, &y);
    return y;
}
