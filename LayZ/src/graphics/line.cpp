#include "graphics/line.h"

namespace lyz { namespace graphics {

	Line::Line(float x1, float y1, float z1, float x2, float y2, float z2, float size):
		m_size()
	{
	}
	
	Line::Line(const coord_t & v1, const coord_t & v2, float size):
		Line(v1.data[0], v1.data[1], v1.data[2], v2.data[0], v2.data[1], v2.data[2], size)
	{
	}

	Line::Line(float x1, float y1, float x2, float y2, float size):
		Line(x1, y1, 0.0, x2, y2, 0.0, size)
	{
	}
	
	Line::Line(const coord2_t & v1, const coord2_t & v2, float size):
		Line(coord_t(v1), coord_t(v2), size)
	{
	}
	
	Line::~Line()
	{
	}
	
	void Line::setThickness(float size)
	{
		m_size = size;
	}

} }