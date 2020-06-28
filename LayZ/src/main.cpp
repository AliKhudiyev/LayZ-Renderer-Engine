#include <iostream>
#include <string>

#include "graphics/graphics.h"
#include "utils/utils.h"

#include "graphics/renderable.h"
#include "graphics/renderer.h"

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

	Renderer* renderer = Renderer::getRenderer();

	vector<coord2_t> coords{
		LYZ_COORD2(-0.5, 0.5),
		LYZ_COORD2(0.5, 0.5),
		LYZ_COORD2(0.5, -0.5),
		LYZ_COORD2(0.0, -0.75),
		LYZ_COORD2(-0.5, -0.5)
	};

	vector<coord2_t> coords2{
		LYZ_COORD2(-1.0, 1.0),
		LYZ_COORD2(0.0, 1.0),
		LYZ_COORD2(0.0, 0.0),
		LYZ_COORD2(-1.0, 0.0)
	};

	vector<coord2_t> tricoords{
		LYZ_COORD2(-0.5, 0.5),
		LYZ_COORD2(0.5, 0.5),
		LYZ_COORD2(0.5, -0.5),
	};

	vector<coord2_t> tricoords2{
		LYZ_COORD2(-0.5, 0.5),
		LYZ_COORD2(-0.5, -0.5),
		LYZ_COORD2(0.5, -0.5),
	};

	Renderable* triangle = new Renderable(tricoords);
	triangle->setColor(LYZ_COLOR3(1.0, 1.0, 1.0));

	Renderable* triangle2 = new Renderable(tricoords2);
	triangle2->setColor(LYZ_COLOR3(1.0, 0.0, 0.0));

	Renderable* sprite = new Renderable(coords);
	sprite->setColor(LYZ_COLOR3(1.0, 0.5, 0.0));

	Renderable* sprite2 = new Renderable(coords2);
	sprite2->setColor(LYZ_COLOR3(0.0, 0.0, 1.0));

	while (win->isRunning())
	{
		renderer->store(sprite);
		renderer->store(sprite2);
		renderer->store(triangle2);
		renderer->store(triangle);
		renderer->draw();

		win->onUpdate();
	}

	return 0;
}