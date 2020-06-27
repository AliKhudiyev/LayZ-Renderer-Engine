#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace lyz { namespace graphics {

	struct EventHandler {
		static void windowSize_callback(GLFWwindow* window, int width, int height);
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void cursor_callback(GLFWwindow* window, double xpos, double ypos);
		static void mouse_callback(GLFWwindow* window, int button, int action, int mods);
	};

	struct EventData {
		int key, scancode, action, mods;
		double xpos, ypos;
		int button;
	};

} }
