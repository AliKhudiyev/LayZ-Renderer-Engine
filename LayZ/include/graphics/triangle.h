#pragma once

#include "renderable.h"

namespace lyz { namespace graphics {

	class Triangle : public Renderable {
	private:
		;

	public:
		Triangle(const coord2_t& v1, const coord2_t& v2, const coord2_t& v3);
		Triangle(const coord2_t& v1, const coord2_t& v2, float height);
		~Triangle();

		;
	};

} }
