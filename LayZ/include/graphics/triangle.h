#pragma once

#include "renderable.h"

namespace lyz { namespace graphics {

	class Triangle : public Renderable {
	public:
		Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
		Triangle(const coord2_t& v1, const coord2_t& v2, const coord2_t& v3);
		Triangle(float x, float y, float baselength, float sidelength);
		Triangle(const coord2_t& center, float baselength, float sidelength);
		Triangle(float x, float y, float length);
		Triangle(const coord2_t& center, float length);
		~Triangle();

		;
	};

} }
