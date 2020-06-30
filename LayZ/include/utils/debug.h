#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <chrono>
#include <cassert>

namespace lyz { namespace utils {

	struct Debugger {
		static GLenum error;
		static std::string msg, info;
		static decltype(std::chrono::high_resolution_clock::now()) m_current_time;

		static void clearError();
		static GLenum getError();
		static void dispatch();
		static void showFPS(float deltatime);
	};

} }

#define LYZ_CALL(x)												\
	x;															\
	lyz::utils::Debugger::getError();							\
	if ( lyz::utils::Debugger::error != GL_NO_ERROR ) {			\
		std::cerr << lyz::utils::Debugger::error << ": ";		\
		std::cerr << lyz::utils::Debugger::msg << std::endl;	\
		assert(false);											\
	}
