#pragma once

#include "graphics/renderable.h"

namespace lyz { namespace graphics {

	class Rectangle : public Renderable {
	private:
		;

	public:
		Rectangle(const coord2_t& point, float width, float height);
		~Rectangle();
	};

} }
