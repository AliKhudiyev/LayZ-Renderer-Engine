#pragma once

#include <vector>

#include "math/lyzm.h"
#include "graphics/texture.h"

#define LYZ_COORD(x,y,z)	coord_t(x,y,z)
#define LYZ_COORD2(x,y)		coord2_t(x,y)
#define LYZ_COLOR(r,g,b,a)	color_t(r,g,b,a)
#define LYZ_COLOR3(r,g,b)	color3_t(r,g,b)
#define LYZ_RGBA(r,g,b,a)	color_t(r / 255.0, g / 255.0, b / 255.0, a)
#define LYZ_RGB(r,g,b)		color3_t(r / 255.0, g / 255.0, b / 255.0)

using coord_t = lyz::math::vec3;
using coord2_t = lyz::math::vec2;
using color_t = lyz::math::vec4;
using color3_t = lyz::math::vec3;
using texture_t = lyz::math::vec2;
using slot_t = float;

namespace lyz { namespace graphics {

	enum RenderableType {
		POINT = 0,
		LINE,
		LINE_STRIP,
		OTHER
	};

	class Renderable {
	protected:
		std::vector<coord_t> m_coords; // clock-wise coords
		std::vector<texture_t> m_texCoords;
		color_t m_color;

		const Texture* m_texture = nullptr;

		RenderableType m_type;

	protected:
		Renderable() = default;

	public:
		Renderable(const std::vector<coord_t>& coords);
		Renderable(const std::vector<coord2_t>& coords);
		~Renderable();

		void setCoords(const std::vector<coord_t>& coords);
		void setCoords(const std::vector<coord2_t>& coords);
		void setCoordAt(unsigned index, const coord_t& coord);
		void setCoordAt(unsigned index, const coord2_t& coord);
		void setColor(const color_t& color);
		void setColor(const color3_t& color);
		void setTexture(const Texture* texture);
		void unsetTexture();
		void setDepth(float depth);
		void noFill(bool fill = false);

		inline const std::vector<coord_t>& getCoords() const { return m_coords; }
		inline const math::vec4& getColor() const { return m_color; }
		inline const std::vector<texture_t>& getTextureCoords() const { return m_texCoords; }
		inline unsigned getTextureID() const { return m_texture? m_texture->getID() : -1; }
		inline RenderableType getType() const { return m_type; }
	};

} }
