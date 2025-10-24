#include"Screen.h"


void Screen::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    new_SC_width = width;
    new_SC_height = height;
    mustUpdateCamera = true;
    
}

bool Screen::init()
{
    // 1. Init GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return false;
    }

    // Set OpenGL version (e.g., 3.3 Core)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 2. Create window
     window = glfwCreateWindow(SC_width, SC_height, title.c_str(), nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    // 3. Load OpenGL functions via GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return false;
    }

    // Set viewport and callback
    glViewport(0, 0, SC_width, SC_height);
    glfwSetFramebufferSizeCallback(window, Screen::framebuffer_size_callback);

    inputManager = std::make_shared<InputManager>(window);

    return true;
}

void Screen::update(const std::shared_ptr<Camera>& camera)
{
    float currentTime = glfwGetTime();
    delta_time = currentTime - lastFrame;
    lastFrame = currentTime;

    glfwSwapBuffers(window);
    glfwPollEvents();
    inputManager->update();
    if (mustUpdateCamera)
    {
        SC_height = new_SC_height;
        SC_width = new_SC_width;
        camera->updateProjectionMatrix((float)SC_width, (float)SC_height);
        mustUpdateCamera = false;
    }
}


bool Screen::is_open()
{
    return !glfwWindowShouldClose(window);
}

float Screen::time() const
{
    return glfwGetTime();
}



Screen::Screen(unsigned int width, unsigned int height, const std::string& title)
    :SC_width(width)
    ,SC_height(height)
    ,title(title)
{
}

Screen::~Screen()
{
    // Cleanup
    std::cout << "delete screen\n";
    glfwDestroyWindow(window);
    glfwTerminate();
}




