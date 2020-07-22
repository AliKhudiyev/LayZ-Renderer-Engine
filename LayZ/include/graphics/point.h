#pragma once

#include "graphics/renderable.h"

#define LYZ_POINT_SQUARE	false
#define LYZ_POINT_CIRCULAR	true

namespace lyz { namespace graphics {

	class Point : public Renderable {
	private:
		static float pointSize;
		static bool pointType;

	public:
		Point(float x, float y, float z = 0.0, float size = 1.0);
		Point(const coord_t& position);
		Point(const coord2_t position);

		static void setSize(float size);
		static void makeCircular(bool isCircular = LYZ_POINT_CIRCULAR);

		inline static float getSize() { return pointSize; }
		inline static bool getType() { return pointType; }
	};

} }
