#pragma once

#include "graphics/renderable.h"

namespace lyz { namespace graphics {

	class Rectangle : public Renderable {
	public:
		Rectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
		Rectangle(const coord2_t& point1, const coord2_t& point2, const coord2_t& point3, const coord2_t& point4);
		Rectangle(float x, float y, float width, float height);
		Rectangle(const coord2_t& point, float width, float height);
		~Rectangle();

		void setDepth(float depth) override;
	};

} }
