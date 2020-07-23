#include "graphics/circle.h"

namespace lyz { namespace graphics {

	Circle::Circle(float x, float y, float z, float radius):
		Oval(x, y, z, radius, radius)
	{
	}

	Circle::Circle(const math::vec3 & center, float radius):
		Oval(center, radius, radius)
	{
	}

	Circle::Circle(float x, float y, float radius):
		Oval(x, y, radius, radius)
	{
	}

	Circle::Circle(const math::vec2 & center, float radius):
		Oval(center, radius, radius)
	{
	}

	Circle::~Circle()
	{
	}

} }