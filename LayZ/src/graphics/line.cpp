#include "graphics/line.h"

namespace lyz { namespace graphics {

	float Line::lineSize = 1.0f;

	Line::Line(float x1, float y1, float z1, float x2, float y2, float z2, float size)
	{
		Line::lineSize = size;

		m_coords.push_back(coord_t(x1, y1, z1));
		m_coords.push_back(coord_t(x2, y2, z2));
		m_type = RenderableType::LINE;
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
		Line::lineSize = size;

		LYZ_CALL(glLineWidth(Line::lineSize));
	}

	void Line::setSize(float size)
	{
		setThickness(size);
	}

	void Line::setDepth(float depth)
	{
		m_coords[0].data[2] = depth;
		m_coords[1].data[2] = depth;
	}

} }