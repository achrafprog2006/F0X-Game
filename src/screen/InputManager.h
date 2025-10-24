#pragma once

#include <GLFW/glfw3.h>
#include <unordered_map>

class InputManager {
private:
    GLFWwindow* window;
    std::unordered_map<int, bool> keyDown;
    std::unordered_map<int, bool> mouseDown;

public:
    InputManager(GLFWwindow* win);

    void update();

    bool isKeyPressed(int key);
    bool isKeyJustPressed(int key);

    bool isMousePressed(int button);
    bool isMouseJustPressed(int button);

    double getMouseX() const;
    double getMouseY() const;
};

