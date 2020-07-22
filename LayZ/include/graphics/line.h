#pragma once

#include "graphics/renderable.h"

namespace lyz { namespace graphics {

	class Line : public Renderable {
	private:
		static float lineSize;

	public:
		Line(float x1, float y1, float z1, float x2, float y2, float z2, float size = 1.0);
		Line(const coord_t& v1, const coord_t& v2, float size = 1.0);
		Line(float x1, float y1, float x2, float y2, float size = 1.0);
		Line(const coord2_t& v1, const coord2_t& v2, float size = 1.0);
		~Line();

		static void setThickness(float size);
		static void setSize(float size);

		inline static float getThickness() { return Line::lineSize; }
		inline static float getSize() { return Line::lineSize; }
	};

} }
