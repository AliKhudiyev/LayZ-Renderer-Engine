#include "graphics/point.h"

namespace lyz { namespace graphics {

	Point::Point(float x, float y, float z, float size):
		m_size(size)
	{
		m_coords.push_back(coord_t(x, y, z));

		m_type = RenderableType::POINT;
	}

	Point::Point(const coord_t & position):
		Point(position.data[0], position.data[1], position.data[2])
	{
	}
	
	Point::Point(const coord2_t position):
		Point(position.data[0], position.data[1])
	{
	}
	
	void Point::setSize(float size)
	{
		m_size = size;
	}
	
	void Point::makeCircular(bool isCircular)
	{
		m_isCircular = isCircular;
	}

} }