#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics/window.h"
#include "graphics/shader.h"

#include "utils/utils.h"

using namespace std;

using namespace lyz;

int main() {

	Window* win = new Window("BIG KAMAL", 640, 480);

	Shader* shader = new Shader("src/shaders/vertex.glsl", "src/shaders/fragment.glsl");
	shader->enable();

	float vertices[] = {
		-1.0, -1.0, 0.0,	1.0, 0.0, 0.0,
		1.0, -1.0, 0.0,		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,		0.0, 0.0, 1.0
	};

	GLuint vertexArray;
	LYZ_CALL(glGenVertexArrays(1, &vertexArray));
	LYZ_CALL(glBindVertexArray(vertexArray));

	GLuint vertexBuffer;
	LYZ_CALL(glGenBuffers(1, &vertexBuffer));
	LYZ_CALL(glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer));
	LYZ_CALL(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));
	
	LYZ_CALL(glEnableVertexAttribArray(0));
	LYZ_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0));
	
	LYZ_CALL(glEnableVertexAttribArray(1));
	LYZ_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float))));

	while (win->isRunning())
	{

		LYZ_CALL(glDrawArrays(GL_TRIANGLES, 0, 3));

		win->onUpdate();

		//cout << win->getEventData().xpos << ", " << win->getEventData().ypos << endl;
	}

	return 0;
}