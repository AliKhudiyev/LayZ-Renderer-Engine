cmake_minimum_required(VERSION 3.1.0)
project(LayZ)

# -------------------- SET VARIABLES --------------------
set(PROJECT_PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(PROJECT_DIR "${PROJECT_PARENT_DIR}/LayZ")
set(CMAKE_SOURCE_DIR ${PROJECT_DIR}/src)
set(EXECUTABLE_NAME "lyz")

set(PROJECT_CXX_FLAGS "-Wall -Wextra")

# -------------------- FIND GL PACKAGES --------------------
find_package(OpenGL REQUIRED)

if (UNIX)
    message("Building for Unix...")

    find_package(glfw3 REQUIRED)
    find_package(GLEW REQUIRED)
    endif()

if (WIN32)
    message("Building for Windows...")
    message("God bless you, son!")

    add_compile_definitions("GLEW_STATIC")
    add_compile_definitions("_USE_MATH_DEFINES")

    add_subdirectory(${PROJECT_PARENT_DIR}/Libs/GLFW/glfw-3.3.2)
    set(${GLFW_INCLUDE_DIRS} ${PROJECT_PARENT_DIR}/Libs/GLFW/glfw-3.3.2/include)

    set(GLEW_INCLUDE_DIRS ${PROJECT_PARENT_DIR}/Libs/GLEW/glew-2.1.0/include)
    set(GLEW_LIBRARIES ${PROJECT_PARENT_DIR}/Libs/GLEW/glew-2.1.0/lib/libglew32.a)
endif()

# -------------------- SET SOURCE FILES --------------------
set(SOURCES
        ${CMAKE_SOURCE_DIR}/main.cpp
        ${CMAKE_SOURCE_DIR}/graphics/buffers/buffer.cpp
        ${CMAKE_SOURCE_DIR}/graphics/buffers/indexBuffer.cpp
        ${CMAKE_SOURCE_DIR}/graphics/buffers/vertexArray.cpp
        ${CMAKE_SOURCE_DIR}/graphics/buffers/vertexBuffer.cpp
        ${CMAKE_SOURCE_DIR}/graphics/event.cpp
        ${CMAKE_SOURCE_DIR}/graphics/instanceRenderer.cpp
        ${CMAKE_SOURCE_DIR}/graphics/pixelRenderer.cpp
        ${CMAKE_SOURCE_DIR}/graphics/renderable.cpp
        ${CMAKE_SOURCE_DIR}/graphics/renderer.cpp
        ${CMAKE_SOURCE_DIR}/graphics/shader.cpp
        ${CMAKE_SOURCE_DIR}/graphics/window.cpp
        ${CMAKE_SOURCE_DIR}/math/mat4.cpp
        ${CMAKE_SOURCE_DIR}/math/vec2.cpp
        ${CMAKE_SOURCE_DIR}/math/vec3.cpp
        ${CMAKE_SOURCE_DIR}/math/vec4.cpp
        ${CMAKE_SOURCE_DIR}/utils/debug.cpp
        ${CMAKE_SOURCE_DIR}/utils/file.cpp)

# -------------------- CREATE AN EXECUTABLE --------------------
add_executable(${EXECUTABLE_NAME} ${SOURCES})

# -------------------- LINK AND INCLUDE LIBRARIES --------------------
target_include_directories(${EXECUTABLE_NAME}
        PUBLIC
            ${PROJECT_DIR}/include
            ${GLEW_INCLUDE_DIRS}
            ${GLFW_INCLUDE_DIRS}
            ${OPENGL_INCLUDE_DIR})

target_link_libraries(${EXECUTABLE_NAME}
        ${OPENGL_gl_LIBRARY}
        ${GLEW_LIBRARIES}
        glfw)

# -------------------- COMPILER FLAGS AND FEATURES --------------------
set_target_properties(${EXECUTABLE_NAME}
        PROPERTIES
            CXX_STANDARD 11
            CXX_STANDARD_REQUIRED YES
            CXX_EXTENSIONS NO
        FLAGS
            ${PROJECT_CXX_FLAGS})
