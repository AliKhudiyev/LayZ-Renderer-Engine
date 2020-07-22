#pragma once

#include "graphics/renderable.h"

namespace lyz { namespace graphics {

	class Circle : public Renderable {
	private:
		math::vec3 m_center;
		float m_radius;
		unsigned m_nVertices;

	public:
		Circle(float x, float y, float z, float radius);
		Circle(const math::vec3& center, float radius);
		Circle(float x, float y, float radius);
		Circle(const math::vec2& center, float radius);
		~Circle();

		void setSmoothness(float level);
		void setNVertices(unsigned nvertices);

		inline unsigned getNVertices() const { return m_nVertices; }
	
	private:
		unsigned getOptimizedNVertices() const;
		void construct();
	};

} }
