#pragma once

#include "graphics/renderable.h"

#define LYZ_POINT_SQUARE	false
#define LYZ_POINT_CIRCULAR	true

namespace lyz { namespace graphics {

	class Point : public Renderable {
	private:
		float m_size;
		bool m_isCircular;

	public:
		Point(float x, float y, float z = 0.0, float size = 1.0);
		Point(const coord_t& position);
		Point(const coord2_t position);

		void setSize(float size);
		void makeCircular(bool isCircular = LYZ_POINT_CIRCULAR);
	};

} }
