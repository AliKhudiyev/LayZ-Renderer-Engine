#include <iostream>
#include <string>

#include "graphics/graphics.h"
#include "utils/utils.h"

using namespace std;

using namespace lyz;
using namespace graphics;

int main() {

	Window* win = new Window("BIG KAMAL", 640, 480);

	Shader* shader = new Shader("src/shaders/vertex.glsl", "src/shaders/fragment.glsl");
	shader->enable();

	float vertices[] = {
		-0.5, -0.5, 0.0,	1.0, 1.0, 0.0, 1.0,
		0.5, -0.5, 0.0,		1.0, 1.0, 0.0, 1.0,
		0.5, 0.5, 0.0,		0.0, 0.0, 1.0, 1.0,
		-0.5, 0.5, 0.0,		0.0, 0.0, 1.0, 1.0
	};

	VertexArray va;
	VertexBuffer vb(vertices, sizeof(vertices));
	vb.setLayout({3,4});

	unsigned indices[] = {
		0, 1, 2,
		0, 2, 3 
	};
	
	IndexBuffer ib(indices, sizeof(indices));
	
	while (win->isRunning())
	{
		LYZ_CALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

		win->onUpdate();

		//cout << win->getEventData().xpos << ", " << win->getEventData().ypos << endl;
	}

	return 0;
}