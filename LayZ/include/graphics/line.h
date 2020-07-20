#pragma once

#include "graphics/renderable.h"

namespace lyz { namespace graphics {

	class Line : public Renderable {
	private:
		float m_size;

	public:
		Line(float x1, float y1, float z1, float x2, float y2, float z2, float size = 1.0);
		Line(const coord_t& v1, const coord_t& v2, float size = 1.0);
		Line(float x1, float y1, float x2, float y2, float size = 1.0);
		Line(const coord2_t& v1, const coord2_t& v2, float size = 1.0);
		~Line();

		void setThickness(float size);
		void setDepth(float depth) override { /* TO DO */ }
	};

} }
