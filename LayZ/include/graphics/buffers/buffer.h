#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "utils/debug.h"

namespace lyz { namespace graphics {

	class Buffer {
	protected:
		GLuint m_ID;

	public:
		Buffer() = default;
		virtual ~Buffer() {};

		virtual void enable() const = 0;
		virtual void disable() const = 0;
	};

} }
