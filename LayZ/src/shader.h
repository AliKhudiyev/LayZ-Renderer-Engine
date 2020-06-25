#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace lyz {

	class Shader {
	private:
		unsigned m_ID;

		const char *m_vertexpath, *m_fragmentpath;

	public:
		Shader(const char* vertexpath, const char* fragmentpath);
		~Shader();

		void enable() const;
		void disable() const;

	private:
		void init();
	};

}
