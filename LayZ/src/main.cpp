#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "graphics/window.h"
#include "graphics/shader.h"

using namespace std;

using namespace lyz;

int main() {

	Window* win = new Window("BIG_KAMAL", 640, 480);

	Shader* shader = new Shader("src/shaders/vertex.glsl", "src/shaders/fragment.glsl");
	shader->enable();

	float vertices[] = {
		-1.0, -1.0, 0.0,
		1.0, -1.0, 0.0,
		0.0, 1.0, 0.0
	};

	GLuint vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	while (win->isRunning())
	{
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		shader->enable();

		glDrawArrays(GL_TRIANGLES, 0, 3);

		win->onUpdate();

		//cout << win->getEventData().xpos << ", " << win->getEventData().ypos << endl;
	}

	return 0;
}