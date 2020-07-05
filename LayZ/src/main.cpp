#include <iostream>
#include <string>

#include "graphics/graphics.h"
#include "utils/utils.h"

#include "graphics/renderable.h"
#include "graphics/renderer.h"
#include "graphics/instanceRenderer.h"
#include "graphics/pixelRenderer.h"

#include "graphics/triangle.h"
#include "graphics/rectangle.h"

using namespace std;

using namespace lyz;
using namespace graphics;
using namespace utils;

#define WIDTH 640
#define HEIGHT 480

int main() {

	Window* win = new Window("BIG KAMAL", WIDTH, HEIGHT);

	//glfwSwapInterval(0);

	Shader* shader = new Shader("src/shaders/vertex.glsl", "src/shaders/fragment.glsl");
	shader->enable();

	float vertices[] = {
		-0.5, -0.5, 0.0,	1.0, 1.0, 0.0, 1.0,
		0.5, -0.5, 0.0,		1.0, 1.0, 0.0, 1.0,
		0.5, 0.5, 0.0,		0.0, 0.0, 1.0, 1.0,
		-0.5, 0.5, 0.0,		0.0, 0.0, 1.0, 1.0
	};

	Renderer* renderer = Renderer::getRenderer();
	InstanceRenderer* instanceRenderer = InstanceRenderer::getRenderer();
	PixelRenderer* pixelRenderer = PixelRenderer::getRenderer(WIDTH, HEIGHT);

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

	vector<coord_t> pcoords{
		LYZ_COORD(1.0, 1.0, 0.0),
		LYZ_COORD(0.0, 1.0, 0.0),
		LYZ_COORD(0.0, 0.0, 0.0),
		LYZ_COORD(1.0, 0.0, 0.0)
	};

	Renderable* triangle = new Renderable(tricoords);
	triangle->setColor(LYZ_COLOR3(1.0, 1.0, 1.0));

	Renderable* triangle2 = new Renderable(tricoords2);
	triangle2->setColor(LYZ_COLOR3(1.0, 0.0, 0.0));

	Renderable* sprite = new Renderable(coords);
	sprite->setColor(LYZ_COLOR3(1.0, 0.5, 0.0));

	Renderable* sprite2 = new Renderable(coords2);
	sprite2->setColor(LYZ_COLOR3(0.0, 0.0, 1.0));

	Renderable* plane = new Renderable(pcoords);
	plane->setColor(LYZ_COLOR3(0.0, 1.0, 0.0));

	pixelRenderer->setPixelWidth(40);
	pixelRenderer->setPixelHeight(40);

	while (win->isRunning())
	{
		//renderer->store(sprite);
		//renderer->store(sprite2);
		//renderer->store(triangle2);
		//renderer->store(triangle);
		// renderer->store(plane);
		//renderer->draw();

		//Rectangle* rect = new Rectangle(LYZ_COORD2(0.0, 0.0), 50.0, 50.0);
		//rect->setColor(LYZ_COLOR3(1.0, 0.0, 0.0));
		//renderer->store(rect);
		//renderer->draw();

		Debugger::showFPS(1.0);
		//instanceRenderer->store(sprite);
		//instanceRenderer->store(sprite2);
		//instanceRenderer->store(triangle);
		//instanceRenderer->store(triangle2);
		//instanceRenderer->draw();

		float r, g, b;
		for (unsigned i = 0; i < HEIGHT; ++i) {
			for (unsigned j = 0; j < WIDTH; ++j) {
				if (i < 150) {
					if (j < 50) {
						b = 0.0;
					}
					else {
						b = 1.0;
					}
					r = 1.0;
					g = 0.0;
				}
				else {
					if (j < 50) {
						b = 0.0;
					}
					else {
						b = 1.0;
					}
					r = 0.0;
					g = 1.0;
				}
				pixelRenderer->setPixelAt(0, 0, LYZ_COLOR3(1.0, 1.0, 1.0));
				//pixelRenderer->setPixelAt(0, 1, LYZ_COLOR3(0.0, 1.0, 0.0));

				//pixelRenderer->setPixelAt(1, 0, LYZ_COLOR3(0.0, 0.0, 1.0));
				//pixelRenderer->setPixelAt(1, 1, LYZ_COLOR3(1.0, 1.0, 1.0));
			}
		}
		// cout << pixelRenderer->getPixelAt(100) << endl;
		pixelRenderer->draw();

		win->onUpdate();
	}

	return 0;
}