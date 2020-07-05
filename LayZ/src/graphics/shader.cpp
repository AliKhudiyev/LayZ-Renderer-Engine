#include "graphics/shader.h"

#include "utils/utils.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

namespace lyz { namespace graphics {

	Shader::Shader(const char * vertexpath, const char * fragmentpath) :
		m_vertexpath(vertexpath), m_fragmentpath(fragmentpath)
	{
		init();

		load(vertexpath, fragmentpath);
	}

	Shader::~Shader()
	{
		LYZ_CALL(glDeleteProgram(m_ID));
	}

	void Shader::enable() const
	{
		LYZ_CALL(glUseProgram(m_ID));
	}

	void Shader::disable() const
	{
		LYZ_CALL(glUseProgram(0));
	}

	void Shader::load(const char * vertexpath, const char * fragmentpath)
	{
		// Vertex Shader
		GLuint vertex = LYZ_CALL(glCreateShader(GL_VERTEX_SHADER));

		std::string vertex_str = utils::FileParser::read(vertexpath);
		const char* vertex_chrs = vertex_str.c_str();

		LYZ_CALL(glShaderSource(vertex, 1, &vertex_chrs, nullptr));
		LYZ_CALL(glCompileShader(vertex));

		GLint success;
		char infoLog[LYZ_INFOLOG_SIZE];
		LYZ_CALL(glGetShaderiv(vertex, GL_COMPILE_STATUS, &success));
		if (!success)
		{
			LYZ_CALL(glGetShaderInfoLog(vertex, LYZ_INFOLOG_SIZE, nullptr, infoLog));
			std::cout << "ERROR[shader]:Vertex compilation failed!\n" << infoLog << std::endl;
			assert(false);
		};

		LYZ_CALL(glAttachShader(m_ID, vertex));
		LYZ_CALL(glLinkProgram(m_ID));
		LYZ_CALL(glGetProgramiv(m_ID, GL_LINK_STATUS, &success));
		if (!success)
		{
			LYZ_CALL(glGetProgramInfoLog(m_ID, LYZ_INFOLOG_SIZE, nullptr, infoLog));
			std::cout << "ERROR[shader]:program linking failed!\n" << infoLog << std::endl;
		}
		LYZ_CALL(glDeleteShader(vertex));

		// Fragment Shader
		GLuint fragment = LYZ_CALL(glCreateShader(GL_FRAGMENT_SHADER));

		std::string fragment_str = utils::FileParser::read(fragmentpath);
		const char* fragment_chrs = fragment_str.c_str();

		LYZ_CALL(glShaderSource(fragment, 1, &fragment_chrs, nullptr));
		LYZ_CALL(glCompileShader(fragment));

		LYZ_CALL(glGetShaderiv(fragment, GL_COMPILE_STATUS, &success));
		if (!success)
		{
			LYZ_CALL(glGetShaderInfoLog(fragment, LYZ_INFOLOG_SIZE, nullptr, infoLog));
			std::cout << "ERROR[shader]:fragment compilation failed!\n" << infoLog << std::endl;
			assert(false);
		};

		LYZ_CALL(glAttachShader(m_ID, fragment));
		LYZ_CALL(glLinkProgram(m_ID));
		LYZ_CALL(glGetProgramiv(m_ID, GL_LINK_STATUS, &success));
		if (!success)
		{
			LYZ_CALL(glGetProgramInfoLog(m_ID, LYZ_INFOLOG_SIZE, nullptr, infoLog));
			std::cout << "ERROR[shader]:program linking failed!\n" << infoLog << std::endl;
		}
		LYZ_CALL(glDeleteShader(fragment));
	}

	void Shader::init()
	{
		m_ID = LYZ_CALL(glCreateProgram());
	}

} }