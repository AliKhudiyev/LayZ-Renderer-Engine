cmake_minimum_required(VERSION 3.1)

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

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

get_filename_component(LIBNAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_library(${LIBNAME} STATIC ${SOURCES})

subdirlist(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
list(LENGTH SUBDIRS SUBDIRS_LEN)
if (${SUBDIRS_LEN} GREATER 0)
    foreach(SUBDIR ${SUBDIRS})
        if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/CMakeLists.txt)
            add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
            target_link_libraries(${LIBNAME} ${SUBDIR})
        endif()
    endforeach(SUBDIR)
endif()