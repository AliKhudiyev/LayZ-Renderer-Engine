#include "window.h"

#include <iostream>

namespace lyz {

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

		/* Make the window's context current */
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
		glfwSwapBuffers(m_window);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
	}

	bool Window::init()
	{
		if (!glfwInit()) {
			std::cerr << "ERROR[glfw]: glfw failed!\n";
			assert(false);
			return false;
		}
	}

}