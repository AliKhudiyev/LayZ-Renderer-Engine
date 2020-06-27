#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cassert>

#include "event.h"

namespace lyz { namespace graphics {

	class Window {
		friend struct EventHandler;

	private:
		unsigned width, height;
		GLFWwindow* m_window;

		EventData m_eventData;

	public:
		Window(const char* title, unsigned width, unsigned height);
		~Window();

		bool isRunning() const;
		void onUpdate() const;
		inline const EventData& getEventData() const { return m_eventData; }

	private:
		bool init();
	};

} }
