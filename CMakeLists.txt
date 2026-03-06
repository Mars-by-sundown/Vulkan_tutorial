cmake_minimum_required(VERSION 4.0...4.3)
project(Vulkan_tutorial)

set(CMAKE_CXX_STANDARD 20)


include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)

find_package(slang CONFIG HINTS "$ENV{VULKAN_SDK}/lib/cmake")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG        1.0.1
)
FetchContent_MakeAvailable(glm)

FetchContent_Declare(
    tinyobjloader
    GIT_REPOSITORY https://github.com/tinyobjloader/tinyobjloader.git
    GIT_TAG        v2.0.0rc13
)
FetchContent_MakeAvailable(tinyobjloader)

find_package(Vulkan REQUIRED)

add_executable(VulkanApp src/main.cpp)

target_compile_definitions(VulkanApp PRIVATE
    VULKAN_HPP_NO_CONSTRUCTORS
)


target_include_directories(VulkanApp PRIVATE ${Vulkan_INCLUDE_DIRS})

target_link_libraries(VulkanApp PRIVATE 
    Vulkan::Vulkan
    glfw
    glm::glm
    tinyobjloader)

