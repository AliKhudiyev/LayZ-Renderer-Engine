#include "graphics/shader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

namespace lyz {

	Shader::Shader(const char * vertexpath, const char * fragmentpath) :
		m_vertexpath(vertexpath), m_fragmentpath(fragmentpath)
	{
		std::string vertex;
		std::ifstream vertexFile(vertexpath);
		
		if (!vertexFile) {
			std::cerr << "ERROR[shader]: Cannot open vertex file!\n";
			assert(false);
		}
		;
		vertexFile.close();
	}

	Shader::~Shader()
	{
	}

	void Shader::enable() const
	{
	}

	void Shader::disable() const
	{
	}

	void Shader::init()
	{
		m_ID = glCreateProgram();
	}

}