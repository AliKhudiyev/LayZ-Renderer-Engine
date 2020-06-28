#include "graphics/renderable.h"

namespace lyz { namespace graphics {

	Renderable::Renderable(const std::vector<coord_t>& coords):
		m_coords(coords)
	{
	}
	
	Renderable::Renderable(const std::vector<coord2_t>& coords)
	{
		for (const auto& coord : coords)
			m_coords.push_back(coord_t(coord, 0.0));
	}

	Renderable::~Renderable()
	{
	}
	
	void Renderable::setColor(const color_t & color)
	{
		m_color = color;
	}
	
	void Renderable::setColor(const color3_t & color)
	{
		m_color = color_t(color, 1.0);
	}

} }