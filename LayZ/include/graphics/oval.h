#pragma once

#include "graphics/renderable.h"

namespace lyz { namespace graphics {

	class Oval : public Renderable {
	private:
		math::vec3 m_center;
		float m_xradius, m_yradius;
		unsigned m_nVertices;

	public:
		Oval(float x, float y, float z, float xradius, float yradius);
		Oval(const math::vec3& center, float xradius, float yradius);
		Oval(float x, float y, float xradius, float yradius);
		Oval(const math::vec2& center, float xradius, float yradius);
		~Oval();

		void setSmoothness(float level);
		void setNVertices(unsigned nvertices);

		inline unsigned getNVertices() const { return m_nVertices; }
	
	private:
		unsigned getOptimizedNVertices() const;
		void construct();
	};

} }
