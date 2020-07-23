#pragma once

#include "graphics/renderable.h"
#include "graphics/triangle.h"
#include "graphics/rectangle.h"

namespace lyz { namespace graphics {

	class Pyramid : public Renderable {
	private:
		Triangle* m_sides[4];
		Rectangle* m_bottom;

	protected:
		Pyramid() = default;

	public:
		Pyramid(float x, float y, float z, float height, float baselength);
		Pyramid(const math::vec3& v, float height, float baselength);
		Pyramid(float x, float y, float z, float height);
		Pyramid(const math::vec3& v, float height);
		~Pyramid();

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
