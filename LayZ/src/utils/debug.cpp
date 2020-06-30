#include "utils/debug.h"

namespace lyz { namespace utils {

	GLenum Debugger::error = GL_NO_ERROR;
	std::string Debugger::msg = "";
	std::string Debugger::info = "";
	decltype(std::chrono::high_resolution_clock::now()) Debugger::m_current_time;

	void Debugger::clearError()
	{
		while (glGetError() != GL_NO_ERROR);
	}

	GLenum Debugger::getError()
	{
		Debugger::error = glGetError();
		Debugger::dispatch();
		return Debugger::error;
	}

	void Debugger::dispatch() 
	{
		switch (Debugger::error) {
		case 0x0500: msg = "GL_INVALID_ENUM";
			info = "Given when an enumeration parameter is not a \
				legal enumeration for that function. This is given \
				only for local problems; if the spec allows the \
				enumeration in certain circumstances, where other \
				parameters or state dictate those circumstances, \
				then GL_INVALID_OPERATION is the result instead.";
			break;
		case 0x0501: msg = "GL_INVALID_VALUE";
			info = "Given when a value parameter is not a legal value \
			for that function. This is only given for local problems; \
			if the spec allows the value in certain circumstances, \
			where other parameters or state dictate those circumstances, \
			then GL_INVALID_OPERATION is the result instead.";
			break;
		case 0x0502: msg = "GL_INVALID_OPERATION";
			info = "Given when the set of state for a command is not \
			legal for the parameters given to that command. It is also \
			given for commands where combinations of parameters define \
			what the legal parameters are.";
			break;
		case 0x0503: msg = "GL_STACK_OVERFLOW";
			info = "Given when a stack pushing operation cannot be done \
			because it would overflow the limit of that stack's size.";
			break;
		case 0x0504: msg = "GL_STACK_UNDERFLOW";
			info = "Given when a stack popping operation cannot be done \
			because the stack is already at its lowest point.";
			break;
		case 0x0505: msg = "GL_OUT_OF_MEMORY";
			info = "Given when performing an operation that can allocate \
			memory, and the memory cannot be allocated. The results of \
			OpenGL functions that return this error are undefined; it is \
			allowable for partial execution of an operation to happen in \
			this circumstance.";
			break;
		case 0x0506: msg = "GL_INVALID_FRAMEBUFFER_OPERATION";
			info = "Given when doing anything that would attempt to read \
			from or write/render to a framebuffer that is not complete.";
			break;
		case 0x0507: msg = "GL_CONTEXT_LOST";
			info = "Given if the OpenGL context has been lost, due to a \
			graphics card reset.";
			break;
		case 0x8031: msg = "GL_TABLE_TOO_LARGE";
			info = "Part of the ARB_imaging extension.";
			break;
		default: break;
		}
	}

	void Debugger::showFPS(float deltatime)
	{
		static unsigned n_frame = 1;
		static double fps = 0.;

		if (n_frame == 1) {
			Debugger::m_current_time = std::chrono::high_resolution_clock::now();
		}
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - Debugger::m_current_time);
		double dt = 1e-6 * static_cast<double>(duration.count());

		if (dt >= deltatime) {
			fps = n_frame / dt;
			std::cout << fps << " FPS" << std::endl;
			n_frame = 0;
		}	++n_frame;
	}

} }