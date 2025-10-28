#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include<memory>
#include <thread>
#include <chrono>
#include "InputManager.h"
#include"../entities/Camera.h"

static bool mustUpdateCamera = false;
static int new_SC_width, new_SC_height;

class Screen
{
public:

	std::string title;
	GLFWwindow* window;

	std::shared_ptr<InputManager> inputManager;
	const int FPS = 60;
	const float FRAME_TIME = 1.0/FPS;

	unsigned int SC_width, SC_height;

	float lastFrame = glfwGetTime();
	float delta_time;
	Screen(unsigned int width, unsigned int height, const std::string& title);
	bool init();
	float time()const;
	bool is_open();
	void update(const std::shared_ptr<Camera>& camera);

	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	~Screen();
};