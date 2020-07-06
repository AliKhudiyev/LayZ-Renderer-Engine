#include "graphics/window.h"

#include "utils/debug.h"

#include <iostream>

namespace lyz { namespace graphics {

	Window::Window(const char * title, unsigned width, unsigned height)
	{
		if (!init()) {
			;
		}

		m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
		if (!m_window)
		{
			std::cerr << "ERROR[Window]: Window failed to open!\n";
			glfwTerminate();
			assert(false);
		}

		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, this);
		glfwSetWindowSizeCallback(m_window, EventHandler::windowSize_callback);
		glfwSetKeyCallback(m_window, EventHandler::key_callback);
		glfwSetCursorPosCallback(m_window, EventHandler::cursor_callback);
		glfwSetMouseButtonCallback(m_window, EventHandler::mouse_callback);

		if (glewInit() != GLEW_OK) {
			std::cerr << "ERROR[glew]: glew failed!\n";
			assert(false);
		}

		utils::Debugger::clearError();
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::isRunning() const
	{
		return !glfwWindowShouldClose(m_window);
	}

	void Window::onUpdate() const
	{
		LYZ_CALL(glfwSwapBuffers(m_window));

		LYZ_CALL(glfwPollEvents());
	}

	bool Window::init()
	{
		if (!glfwInit()) {
			std::cerr << "ERROR[glfw]: glfw failed!\n";
			assert(false);
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		return true;
	}

} }