#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics/window.h"

using namespace std;

using namespace lyz;

int main() {

	Window* win = new Window("BIG_KAMAL", 640, 480);

	string vertex_shader = 
		""
		""
		;

	while (win->isRunning())
	{
		;

		win->onUpdate();

		//cout << win->getEventData().xpos << ", " << win->getEventData().ypos << endl;
	}

	return 0;
}