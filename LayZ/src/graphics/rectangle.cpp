#include "graphics/rectangle.h"

#include <cassert>

namespace lyz { namespace graphics {

	Rectangle::Rectangle(float x, float y, float width, float height)
	{
	}

	Rectangle::Rectangle(const coord2_t & point, float width, float height)
	{
		m_coords.push_back(coord_t(point, 0.0));
		m_coords.push_back(coord_t(coord2_t(point.data[0] + width, point.data[1]), 0.0));
		m_coords.push_back(coord_t(coord2_t(point.data[0] + width, point.data[1] - height), 0.0));
		m_coords.push_back(coord_t(coord2_t(point.data[0], point.data[1] - height), 0.0));
	}

	Rectangle::Rectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
	{
		m_coords.push_back(coord2_t(x1, y1));
		m_coords.push_back(coord2_t(x2, y2));
		m_coords.push_back(coord2_t(x3, y3));
		m_coords.push_back(coord2_t(x4, y4));
	}

	Rectangle::Rectangle(const coord2_t & point1, const coord2_t & point2, const coord2_t & point3, const coord2_t & point4)
	{
		m_coords.push_back(point1);
		m_coords.push_back(point2);
		m_coords.push_back(point3);
		m_coords.push_back(point4);
	}
	
	Rectangle::~Rectangle()
	{
	}

} }