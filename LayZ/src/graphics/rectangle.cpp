#include "graphics/rectangle.h"

#include <cassert>

namespace lyz { namespace graphics {

	Rectangle::Rectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
	{
		m_coords.push_back(coord2_t(x1, y1));
		m_coords.push_back(coord2_t(x2, y2));
		m_coords.push_back(coord2_t(x3, y3));
		m_coords.push_back(coord2_t(x4, y4));

		m_type = RenderableType::OTHER;
	}

	Rectangle::Rectangle(const coord2_t & point1, const coord2_t & point2, const coord2_t & point3, const coord2_t & point4):
		Rectangle(point1.data[0], point1.data[1], point2.data[0], point2.data[1], point3.data[0], point3.data[1], point4.data[0], point4.data[1])
	{
	}
	
	Rectangle::Rectangle(float x, float y, float width, float height)
	{
		m_coords.push_back(coord2_t(x, y));
		m_coords.push_back(coord2_t(x + width,	y));
		m_coords.push_back(coord2_t(x + width,	y - height));
		m_coords.push_back(coord2_t(x,			y - height));

		m_type = RenderableType::OTHER;
	}

	Rectangle::Rectangle(const coord2_t & point, float width, float height):
		Rectangle(point.data[0], point.data[1], width, height)
	{
	}
	
	Rectangle::~Rectangle()
	{
	}

	void Rectangle::setDepth(float depth)
	{
		m_coords[0].data[2] = depth;
		m_coords[1].data[2] = depth;
		m_coords[2].data[2] = depth;
		m_coords[3].data[2] = depth;
	}

} }