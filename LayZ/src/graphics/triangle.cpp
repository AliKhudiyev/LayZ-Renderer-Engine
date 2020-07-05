#include "graphics/triangle.h"

namespace lyz { namespace graphics {

	Triangle::Triangle(const coord2_t & v1, const coord2_t & v2, const coord2_t & v3)
	{
		m_coords.push_back(coord_t(v1, 0.0));
		m_coords.push_back(coord_t(v2, 0.0));
		m_coords.push_back(coord_t(v3, 0.0));
	}
	
	Triangle::Triangle(const coord2_t & v1, const coord2_t & v2, float height)
	{
		// TO DO
	}
	
	Triangle::~Triangle()
	{
	}

} }