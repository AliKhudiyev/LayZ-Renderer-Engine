#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "math/lyzm.h"
#include "utils/debug.h"

namespace lyz { namespace graphics {

	class Shader {
	private:
		unsigned m_ID;

		const char *m_vertexpath, *m_fragmentpath;

	public:
		Shader(const char* vertexpath, const char* fragmentpath);
		~Shader();

		void enable() const;
		void disable() const;
		
		template<typename T>
		void setUniform(const char* varname, T val);
		
		template<typename T>
		void setUniform(const char* varname, const math::vec2& vec);
		
		template<typename T>
		void setUniform(const char* varname, const math::vec3& vec);

		template<typename T>
		void setUniform(const char* varname, const math::vec4& vec);

		void setUniform(const char* varname, const math::mat4& mat);
		
	private:
		void init();
		inline GLint getUniformLocation(const char* varname) const {
			LYZ_CALL(GLint location = glGetUniformLocation(m_ID, varname));
			return location;
		}
	};

} }

namespace lyz { namespace graphics {
	
	template<>
	inline void Shader::setUniform<float>(const char * varname, float val)
	{
		GLint location = getUniformLocation(varname);
		LYZ_CALL(glUniform1f(location, val));
	}

	template<>
	inline void Shader::setUniform<int>(const char * varname, int val)
	{
		GLint location = getUniformLocation(varname);
		LYZ_CALL(glUniform1i(location, val));
	}

	template<>
	inline void Shader::setUniform<unsigned>(const char * varname, unsigned val)
	{
		GLint location = getUniformLocation(varname);
		LYZ_CALL(glUniform1ui(location, val));
	}

	template<>
	inline void Shader::setUniform<float>(const char * varname, const math::vec2 & vec)
	{
		GLint location = getUniformLocation(varname);
		LYZ_CALL(glUniform2f(location, 
			vec.data[0], 
			vec.data[1]
		));
	}

	template<>
	inline void Shader::setUniform<int>(const char * varname, const math::vec2 & vec)
	{
		GLint location = getUniformLocation(varname);
		LYZ_CALL(glUniform2i(location, 
			static_cast<int>(vec.data[0]), 
			static_cast<int>(vec.data[1])
		));
	}

	template<>
	inline void Shader::setUniform<unsigned>(const char * varname, const math::vec2 & vec)
	{
		GLint location = getUniformLocation(varname);
		LYZ_CALL(glUniform2ui(location, 
			static_cast<unsigned>(vec.data[0]), 
			static_cast<unsigned>(vec.data[1])
		));
	}

	template<>
	inline void Shader::setUniform<float>(const char * varname, const math::vec3 & vec)
	{
		GLint location = getUniformLocation(varname);
		LYZ_CALL(glUniform3f(location, 
			vec.data[0], 
			vec.data[1], 
			vec.data[2]
		));
	}

	template<>
	inline void Shader::setUniform<int>(const char * varname, const math::vec3 & vec)
	{
		GLint location = getUniformLocation(varname);
		LYZ_CALL(glUniform3i(location, 
			static_cast<int>(vec.data[0]), 
			static_cast<int>(vec.data[1]), 
			static_cast<int>(vec.data[2])
		));
	}

	template<>
	inline void Shader::setUniform<unsigned>(const char * varname, const math::vec3 & vec)
	{
		GLint location = getUniformLocation(varname);
		LYZ_CALL(glUniform3ui(location, 
			static_cast<unsigned>(vec.data[0]), 
			static_cast<unsigned>(vec.data[1]), 
			static_cast<unsigned>(vec.data[2])
		));
	}

	template<>
	inline void Shader::setUniform<float>(const char * varname, const math::vec4 & vec)
	{
		GLint location = getUniformLocation(varname);
		LYZ_CALL(glUniform4f(location, 
			vec.data[0], 
			vec.data[1], 
			vec.data[2], 
			vec.data[3]
		));
	}

	template<>
	inline void Shader::setUniform<int>(const char * varname, const math::vec4 & vec)
	{
		GLint location = getUniformLocation(varname);
		LYZ_CALL(glUniform4i(location, 
			static_cast<int>(vec.data[0]), 
			static_cast<int>(vec.data[1]), 
			static_cast<int>(vec.data[2]), 
			static_cast<int>(vec.data[3])
		));
	}

	template<>
	inline void Shader::setUniform<unsigned>(const char * varname, const math::vec4 & vec)
	{
		GLint location = getUniformLocation(varname);
		LYZ_CALL(glUniform4ui(location, 
			static_cast<unsigned>(vec.data[0]), 
			static_cast<unsigned>(vec.data[1]), 
			static_cast<unsigned>(vec.data[2]), 
			static_cast<unsigned>(vec.data[3])
		));
	}

	inline void Shader::setUniform(const char * varname, const math::mat4 & mat)
	{
		GLint location = getUniformLocation(varname);
		LYZ_CALL(glUniformMatrix4fv(location, 1, GL_FALSE, mat.data));
	}
	
} }
