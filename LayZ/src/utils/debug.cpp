#include "utils/debug.h"

namespace lyz { namespace utils {

	GLenum Debugger::error = GL_NO_ERROR;

	void Debugger::clearError()
	{
		while (glGetError() != GL_NO_ERROR);
	}

	GLenum Debugger::getError()
	{
		Debugger::error = glGetError();
		return Debugger::error;
	}

} }