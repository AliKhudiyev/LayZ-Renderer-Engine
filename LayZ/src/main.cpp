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

	//Shader* shader = new Shader("src/shaders/vertex.glsl", "src/shaders/fragment.glsl");
	//shader->enable();

	Renderer* renderer = Renderer::getRenderer();
	InstanceRenderer* instanceRenderer = InstanceRenderer::getRenderer();
	//PixelRenderer* pixelRenderer = PixelRenderer::getRenderer(WIDTH, HEIGHT);

	Texture* texture1 = new Texture("src/example.bmp");
	Texture* texture2 = new Texture("src/example2.bmp");

	Camera* camera = Camera::getCamera(renderer);
	camera->lookAt(
		{ 0.0, 0.0, 1.0 }, 
		{ 0.0, 0.0, 0.0 }, 
		{ 0.0, 1.0, 0.0 }
	);

	EventData eventData;

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

	//pixelRenderer->setPixelWidth(40);
	//pixelRenderer->setPixelHeight(40);

	coord_t cameraPosition{ 0.0, 0.0, 1.0 };
	coord_t cameraTarget{ 0.0, 0.0, 0.0 };

	while (win->isRunning())
	{
		renderer->clear();
		
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
		
		//pixelRenderer->setPixelAt(0, 0, LYZ_COLOR3(1.0, 1.0, 1.0));
		//pixelRenderer->draw();

		auto tri = new Triangle(0.0, 0.0, 0.5, 1.0);
		tri->setColor(LYZ_COLOR3(0.0, 1.0, 1.0));
		tri->setTexture(texture1);
		auto rct = new Rectangle(0.0, 0.0, 1.0, 1.0);
		rct->setTexture(texture1);
		auto rct2 = new Rectangle(-1.0, 0.0, 0.5, 0.8);
		rct2->setTexture(texture2);
		renderer->store(tri);
		renderer->store(rct);
		renderer->store(rct2);

		renderer->draw();

		win->onUpdate();
		eventData = win->getEventData();

		if (eventData.key == GLFW_KEY_A && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			cameraPosition.data[0] -= 0.1;
		}
		else if (eventData.key == GLFW_KEY_D && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			cameraPosition.data[0] += 0.1;
		}
		else if (eventData.key == GLFW_KEY_W && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			cameraPosition.data[2] -= 0.1;
		}
		else if (eventData.key == GLFW_KEY_S && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			cameraPosition.data[2] += 0.1;
		}
	
		if (eventData.key == GLFW_KEY_UP && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			cameraTarget.data[1] -= 0.1;
		}
		else if (eventData.key == GLFW_KEY_DOWN && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			cameraTarget.data[1] += 0.1;
		}
		else if (eventData.key == GLFW_KEY_LEFT && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			cameraTarget.data[0] += 0.1;
		}
		else if (eventData.key == GLFW_KEY_RIGHT && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			cameraTarget.data[0] -= 0.1;
		}

		camera->lookAt(
			cameraPosition,
			cameraTarget,
			{ 0.0, 1.0, 0.0 }
		);
	}

	return 0;
}