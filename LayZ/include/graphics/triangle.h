#pragma once

#include "renderable.h"

namespace lyz { namespace graphics {

	class Triangle : public Renderable {
	private:
		;

	public:
		Triangle(const math::vec2& v1, const math::vec2& v2, const math::vec2& v3);
		~Triangle();
	};

} }
