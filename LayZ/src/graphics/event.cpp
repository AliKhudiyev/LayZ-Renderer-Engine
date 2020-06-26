#include "graphics/event.h"

#include "graphics/window.h"

namespace lyz {

	void EventHandler::windowSize_callback(GLFWwindow * window, int width, int height)
	{
		auto win = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

		win->width = width;
		win->height = height;

		glViewport(0, 0, width, height);
	}

	void EventHandler::key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
	{
		auto win = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

		win->m_eventData.key = key;
		win->m_eventData.scancode = scancode;
		win->m_eventData.action = action;
		win->m_eventData.mods = mods;
	}

	void EventHandler::cursor_callback(GLFWwindow * window, double xpos, double ypos)
	{
		auto win = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

		win->m_eventData.xpos = xpos;
		win->m_eventData.ypos = ypos;
	}

	void EventHandler::mouse_callback(GLFWwindow * window, int button, int action, int mods)
	{
		auto win = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

		win->m_eventData.button = button;
		win->m_eventData.action = action;
		win->m_eventData.mods = mods;
	}

}