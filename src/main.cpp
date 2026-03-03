#if defined(__INTELLISENSE__) || !defined(USE_CPP20_MODULES)
#include <vulkan/vulkan_raii.hpp>
#else
import vulkan_hpp;
#endif

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>


constexpr uint32_t WIDTH = 800;
constexpr uint32_t HEIGHT = 600;

class HelloTriangleApplication {
public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    void initVulkan() {

    }

    void mainLoop() {
        while(!glfwWindowShouldClose(window)){
            glfwPollEvents();
        }
    }

    void cleanup() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void initWindow(){
        glfwInit(); //initializes the glfw library

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); //do not create openGL context
        glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE); //disable window resizing for now

        //create the window instance
        window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr,nullptr);
    }

private:
    GLFWwindow* window;
};

int main()
{
    try
    {
        HelloTriangleApplication app;
        app.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "failed" << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    std::cerr << "success" << std::endl;
    return EXIT_SUCCESS;
}