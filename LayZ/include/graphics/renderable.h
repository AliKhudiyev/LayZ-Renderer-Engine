#pragma once

#include <vector>
#include "math/lyzm.h"

#define LYZ_COORD(x,y,z)	coord_t(x,y,z)
#define LYZ_COORD2(x,y)		coord2_t(x,y)
#define LYZ_COLOR(r,g,b,a)	color_t(r,g,b,a)
#define LYZ_COLOR3(r,g,b)	color3_t(r,g,b)

using coord_t = lyz::math::vec3;
using coord2_t = lyz::math::vec2;
using color_t = lyz::math::vec4;
using color3_t = lyz::math::vec3;

namespace lyz { namespace graphics {

	class Renderable {
	private:
		std::vector<coord_t> m_coords; // clock-wise coords
		color_t m_color;

	public:
		Renderable(const std::vector<coord_t>& coords);
		Renderable(const std::vector<coord2_t>& coords);
		~Renderable();

		virtual void setColor(const color_t& color);
		virtual void setColor(const color3_t& color);
		virtual void setGradientColor() {};

		inline const std::vector<coord_t>& getCoords() const { return m_coords; }
		inline const math::vec4& getColor() const { return m_color; }
	};

} }
