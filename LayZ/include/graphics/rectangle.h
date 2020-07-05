#pragma once

#include "graphics/renderable.h"

#define LYZ_MOD_ADDITIVE	false
#define LYZ_MOD_SUBTRACTIVE	true

namespace lyz { namespace graphics {

	class Rectangle : public Renderable {
	private:
		;

	public:
		Rectangle(const coord2_t& point, float width, float height);
		~Rectangle();
	
		static bool mod;
	};

} }
