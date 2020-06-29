cmake_minimum_required(VERSION 2.7)
project(LayZ)

# list(APPEND CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_DIR "LayZ")
set(CMAKE_SOURCE_DIR ${PROJECT_DIR}/src)

include_directories(${PROJECT_DIR}/include Libs/GLEW/glew-2.1.0/include Libs/GLFW/glfw-3.3.2/include)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(glfw3 REQUIRED)

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/*.cpp ${CMAKE_SOURCE_DIR}/*/*.cpp ${CMAKE_SOURCE_DIR}/*/*/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} glfw)