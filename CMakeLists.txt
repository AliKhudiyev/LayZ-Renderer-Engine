cmake_minimum_required(VERSION 3.1)
project(LayZ)

macro(subdirlist RESULT CURDIR)
    file(GLOB CHILDREN RELATIVE ${CURDIR} ${CURDIR}/*)
    set(DIRLIST "")
    foreach(CHILD ${CHILDREN})
        if(IS_DIRECTORY ${CURDIR}/${CHILD})
            list(APPEND DIRLIST ${CHILD})
            message(${CURDIR}/${CHILD})
        endif()
    endforeach()
    set(${RESULT} ${DIRLIST})
endmacro()

list(APPEND CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_DIR "LayZ")
set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_DIR}/src)
set(EXECUTABLE_NAME "layz")

include_directories(${PROJECT_DIR}/include)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(glfw3 REQUIRED)

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/*.cpp)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_gl_LIBRARY} glfw)

subdirlist(SUBDIRS ${CMAKE_SOURCE_DIR})
foreach(SUBDIR ${SUBDIRS})
    if (EXISTS ${CMAKE_SOURCE_DIR}/${SUBDIR}/CMakeLists.txt)
        add_subdirectory(${CMAKE_SOURCE_DIR}/${SUBDIR})
        target_link_libraries(${EXECUTABLE_NAME} ${SUBDIR})
    endif()
endforeach(SUBDIR)
