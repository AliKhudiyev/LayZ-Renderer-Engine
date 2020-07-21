#include <iostream>
#include <string>

#include "graphics/graphics.h"
#include "utils/utils.h"

using namespace std;

using namespace lyz;
using namespace graphics;
using namespace utils;

#define WIDTH 640
#define HEIGHT 480

math::vec3 tell_yaw(const math::vec3& vertex, float angle, const math::vec3& axis) {
	return math::rotate(vertex, axis, angle);
}

math::vec3 tell_pitch(const math::vec3& vertex, float angle, const math::vec3& axis) {
	return math::rotate(vertex, axis, angle) - vertex;
}

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

	OrthographicCamera* ocamera = OrthographicCamera::getCamera();
	PerspectiveCamera* pcamera = PerspectiveCamera::getCamera();

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

	coord_t cameraPosition{ 0.0, 0.0, 0.0 };
	coord_t cameraDirection = { 0.0, 0.0, -1.0 };
	coord_t cameraTarget = cameraPosition + cameraDirection;

	//ocamera->setViewSpace(-2.0f, 2.0f, 2.0f, -2.0f, 1.0f, -1.0f);
	//pcamera->setViewSpace(-1.0f, 1.0f, 1.0f, -1.0f, 0.1f, 100.0f);

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

		auto tri = new Triangle(0.0f, 0.0f, 0.5f, 1.0f);
		tri->setColor(LYZ_COLOR3(0.0f, 1.0f, 1.0f));
		tri->setTexture(texture1);

		auto rct = new Rectangle(0.0f, 0.0f, 1.0f, 1.0f);
		//rct->setDepth(-0.2f);
		rct->setTexture(texture1);
		
		auto rct2 = new Rectangle(-1.0f, 0.0f, 0.5f, 0.8f);
		//rct2->setDepth(-0.5f);
		rct2->setTexture(texture2);
		
		auto line1 = new Line(0.0, 0.0, 1.0, 1.0);
		line1->setColor(LYZ_COLOR3(1.0, 0.0, 1.0));

		auto line2 = new Line(0.0, 0.0, -1.0, 1.0);
		line2->setColor(LYZ_COLOR3(0.0, 1.0, 0.0));
		
		auto point1 = new Point(-0.1, 0.1);
		point1->setColor(LYZ_COLOR3(1.0, 1.0, 1.0));

		auto point2 = new Point(-0.1, 0.5);
		point2->setColor(LYZ_COLOR3(1.0, 1.0, 1.0));

		glPointSize(20.0);
		glLineWidth(2.0);

		renderer->store(tri);
		renderer->store(line1);
		renderer->store(line2);
		renderer->store(point1);
		renderer->store(rct);
		renderer->store(point2);
		renderer->store(rct2);

		renderer->draw();
		
		win->onUpdate();
		eventData = win->getEventData();

		if (eventData.key == GLFW_KEY_A && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			cameraPosition.data[0] -= 0.01f;
			cameraTarget = cameraPosition + cameraDirection;
		}
		if (eventData.key == GLFW_KEY_D && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			cameraPosition.data[0] += 0.01f;
		}
		if (eventData.key == GLFW_KEY_W && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			cameraPosition.data[2] -= 0.01f;
		}
		if (eventData.key == GLFW_KEY_S && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			cameraPosition.data[2] += 0.01f;
		}
		if (eventData.key == GLFW_KEY_C && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			cameraPosition.data[1] += 0.01f;
		}
		if (eventData.key == GLFW_KEY_LEFT_CONTROL && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			cameraPosition.data[1] -= 0.01f;
		}

		if (eventData.key == GLFW_KEY_UP && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			//cout << "> cam direction: " << cameraDirection << "\n";
			cameraDirection = tell_yaw(cameraDirection, 1.0, ocamera->getRight());
			//cout << ocamera->getRight() << '\n';
			//cout << "< cam direction: " << cameraDirection << "\n\n";
		}
		else if (eventData.key == GLFW_KEY_DOWN && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			//cout << "> cam direction: " << cameraDirection << "\n";
			cameraDirection = tell_yaw(cameraDirection, -1.0, ocamera->getRight());
			//cout << ocamera->getRight() << '\n';
			//cout << "cam direction: " << cameraDirection << "\n\n";
		}
		else if (eventData.key == GLFW_KEY_LEFT && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			//cout << "> cam direction: " << cameraDirection << "\n";
			cameraDirection = tell_yaw(cameraDirection, 1.0, ocamera->getUp());
			//cout << ocamera->getRight() << '\n';
			//cout << "cam direction: " << cameraDirection << "\n\n";
		}
		else if (eventData.key == GLFW_KEY_RIGHT && (eventData.action == GLFW_PRESS || eventData.action == GLFW_REPEAT)) {
			//cout << "> cam direction: " << cameraDirection << "\n";
			cameraDirection = tell_yaw(cameraDirection, -1.0, ocamera->getUp());
			//cout << ocamera->getRight() << '\n';
			//cout << "cam direction: " << cameraDirection << "\n\n";
		}

		cameraTarget = cameraPosition + cameraDirection;

		ocamera->lookAt(
			cameraPosition,
			cameraTarget,
			{ 0.0, 1.0, 0.0 },
			0.25f * 2.0f
		);

		/*pcamera->lookAt(
			cameraPosition,
			cameraTarget,
			{ 0.0, 1.0, 0.0 }
		);*/
	}

	return 0;
}