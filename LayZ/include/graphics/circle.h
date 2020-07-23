#pragma once

#include "graphics/oval.h"

namespace lyz { namespace graphics {

	class Circle : public Oval {
	public:
		Circle(float x, float y, float z, float radius);
		Circle(const math::vec3& center, float radius);
		Circle(float x, float y, float radius);
		Circle(const math::vec2& center, float radius);
		~Circle();
	};

} }
