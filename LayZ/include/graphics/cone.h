#pragma once

#include "graphics/renderable.h"
#include "graphics/triangle.h"
#include "graphics/oval.h"

namespace lyz { namespace graphics {

	class Cone : public Renderable {
	private:
		math::vec3 m_center;
		float m_xradius, m_yradius, m_height;
		unsigned m_nVertices;
		std::vector<Triangle*> m_sides;
		Oval* m_bottom;

	public:
		Cone(float x, float y, float z, float radius, float height);
		Cone(const math::vec3& v, float radius, float height);
		~Cone();

		void setXRadius(float radius);
		void setYRadius(float radius);
		void setSmoothness(float smoothness);
		void setNVertices(unsigned nvertices);
		void setColor(const color_t& color) override;
		void setColor(const color3_t& color) override;
		void setTexture(const Texture* texture) override;
		void unsetTexture() override;
		void noFill(bool fill = false) override;

		std::vector<const Renderable*> getSubRenderables() const override;

		void translate(float x, float y, float z) override;
		void scale(float xfactor, float yfactor, float zfactor) override;
		void scale(float factor) override;
		void rotate(float angle, const coord_t& axis) override;

	private:
		unsigned getOptimizedNVertices() const;
		void construct();
	};

} }
