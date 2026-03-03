#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

int main() {
    // Test Vulkan
    uint32_t version;
    vkEnumerateInstanceVersion(&version);
    std::cout << "Vulkan version: "
              << VK_VERSION_MAJOR(version) << "."
              << VK_VERSION_MINOR(version) << "."
              << VK_VERSION_PATCH(version) << std::endl;

    // Test GLFW
    if (!glfwInit()) {
        std::cerr << "GLFW failed to initialize" << std::endl;
        return -1;
    }
    std::cout << "GLFW version: " << glfwGetVersionString() << std::endl;
    glfwTerminate();

    // Test GLM
    glm::vec3 testVec(1.0f, 2.0f, 3.0f);
    std::cout << "GLM vec3: "
              << testVec.x << ", "
              << testVec.y << ", "
              << testVec.z << std::endl;

    return 0;
}