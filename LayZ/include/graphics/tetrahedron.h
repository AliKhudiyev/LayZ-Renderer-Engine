#pragma once

#include "graphics/pyramid.h"

namespace lyz { namespace graphics {

	class Tetrahedron : public Pyramid {
	private:
		Triangle* m_faces[4];
	public:
		Tetrahedron(float x, float y, float z, float height);
		Tetrahedron(const math::vec3& v, float height);
		~Tetrahedron();

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
	};

} }
