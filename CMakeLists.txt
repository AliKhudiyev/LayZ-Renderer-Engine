cmake_minimum_required(VERSION 3.1.0)
project(LayZ)

# list(APPEND CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(PROJECT_DIR "${PROJECT_PARENT_DIR}/LayZ")
set(CMAKE_SOURCE_DIR ${PROJECT_DIR}/src)
set(EXECUTABLE_NAME "layz")

include_directories(${PROJECT_DIR}/include ${PROJECT_PARENT_DIR}/Libs/GLEW/glew-2.1.0/include ${PROJECT_PARENT_DIR}/Libs/GLFW/glfw-3.3.2/include)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

if (UNIX)
    message("UNIX settings")

    find_package(glfw3 REQUIRED)
    find_package(GLEW REQUIRED)
    if (GLEW_FOUND)
        include_directories(${GLEW_INCLUDE_DIRS})
        link_libraries(${GLEW_LIBRARIES})
    endif()
endif()

if (WIN32)
    message("Windows setting")

    add_compile_definitions("GLEW_STATIC")

    add_subdirectory(${PROJECT_PARENT_DIR}/Libs/GLFW/glfw-3.3.2)

    include_directories(${PROJECT_PARENT_DIR}/Libs/GLEW/glew-2.1.0/include/GL)
    link_libraries(${PROJECT_PARENT_DIR}/Libs/GLEW/glew-2.1.0/lib/libglew32.a)
endif()

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/*.cpp ${CMAKE_SOURCE_DIR}/*/*.cpp ${CMAKE_SOURCE_DIR}/*/*/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} glfw)