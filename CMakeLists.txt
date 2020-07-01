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

if(UNIX)
    include_directories(${PROJECT_DIR}/include)

    find_package(OpenGL REQUIRED)
    include_directories(${OPENGL_INCLUDE_DIR})
    
    find_package(glfw3 REQUIRED)
    
    find_package(GLEW REQUIRED)
    if (GLEW_FOUND)
        include_directories(${GLEW_INCLUDE_DIRS})
    endif()
    
    link_libraries(${OPENGL_gl_LIBRARY} ${GLEW_LIBRARIES} glfw)
endif(UNIX)

if (WIN32)
    include_directories(${PROJECT_DIR}/include Libs/GLEW/include Libs/GLFW/include)
    find_package(OpenGL REQUIRED)
    include_directories(${OPENGL_INCLUDE_DIR})
    
    link_libraries(${OPENGL_gl_LIBRARY} "Libs/GLEW/lib/Win32/glew32.lib" "Libs/GLFW/lib-vc2015/glfw3.lib")
endif(WIN32)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/*.cpp)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

subdirlist(SUBDIRS ${CMAKE_SOURCE_DIR})
foreach(SUBDIR ${SUBDIRS})
    if (EXISTS ${CMAKE_SOURCE_DIR}/${SUBDIR}/CMakeLists.txt)
        add_subdirectory(${CMAKE_SOURCE_DIR}/${SUBDIR})
        target_link_libraries(${EXECUTABLE_NAME} ${SUBDIR})
    endif()
endforeach(SUBDIR)
