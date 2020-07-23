#pragma once

#include "graphics/renderable.h"
#include "graphics/rectangle.h"

namespace lyz { namespace graphics {

	class Cuboid : public Renderable {
	private:
		Rectangle* m_faces[6];

	public:
		Cuboid(float x, float y, float z, float width, float height, float depth);
		Cuboid(const math::vec3& v, float width, float height, float depth);
		~Cuboid();

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
