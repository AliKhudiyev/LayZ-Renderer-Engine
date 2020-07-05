#include "graphics/rectangle.h"

namespace lyz { namespace graphics {

	Rectangle::Rectangle(const coord2_t & point, float width, float height)
	{
		m_coords.push_back(coord_t(point, 0.0));
		m_coords.push_back(coord_t(coord2_t(point.data[0] + width, point.data[1]), 0.0));
		m_coords.push_back(coord_t(coord2_t(point.data[0] + width, point.data[1] - height), 0.0));
		m_coords.push_back(coord_t(coord2_t(point.data[0], point.data[1] - height), 0.0));
	}
	
	Rectangle::~Rectangle()
	{
	}

} }