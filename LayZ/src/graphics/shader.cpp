#include "graphics/shader.h"

#include "utils/utils.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

namespace lyz {

	Shader::Shader(const char * vertexpath, const char * fragmentpath) :
		m_vertexpath(vertexpath), m_fragmentpath(fragmentpath)
	{
		init();

		// Vertex Shader
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);

		std::string vertex_str = utils::FileParser::read(vertexpath);
		const char* vertex_chrs = vertex_str.c_str();

		glShaderSource(vertex, 1, &vertex_chrs, nullptr);
		glCompileShader(vertex);
		
		GLint success;
		char infoLog[LYZ_INFOLOG_SIZE];
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, LYZ_INFOLOG_SIZE, nullptr, infoLog);
			std::cout << "ERROR[shader]:Vertex compilation failed!\n" << infoLog << std::endl;
			assert(false);
		};

		glAttachShader(m_ID, vertex);
		glLinkProgram(m_ID);
		glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(m_ID, LYZ_INFOLOG_SIZE, nullptr, infoLog);
			std::cout << "ERROR[shader]:program linking failed!\n" << infoLog << std::endl;
		}
		glDeleteShader(vertex);

		// Fragment Shader
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

		std::string fragment_str = utils::FileParser::read(fragmentpath);
		const char* fragment_chrs = fragment_str.c_str();

		glShaderSource(fragment, 1, &fragment_chrs, nullptr);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, LYZ_INFOLOG_SIZE, nullptr, infoLog);
			std::cout << "ERROR[shader]:fragment compilation failed!\n" << infoLog << std::endl;
			assert(false);
		};

		glAttachShader(m_ID, fragment);
		glLinkProgram(m_ID);
		glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(m_ID, LYZ_INFOLOG_SIZE, nullptr, infoLog);
			std::cout << "ERROR[shader]:program linking failed!\n" << infoLog << std::endl;
		}
		glDeleteShader(fragment);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_ID);
	}

	void Shader::enable() const
	{
		glUseProgram(m_ID);
	}

	void Shader::disable() const
	{
		glUseProgram(0);
	}

	void Shader::init()
	{
		m_ID = glCreateProgram();
	}

}