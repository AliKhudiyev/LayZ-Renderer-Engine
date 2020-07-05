#include "graphics/rectangle.h"

#include <cassert>

namespace lyz { namespace graphics {

	bool Rectangle::mod = LYZ_MOD_SUBTRACTIVE;

	Rectangle::Rectangle(const coord2_t & point, float width, float height)
	{
		float sign = -1.0;
		if (Rectangle::mod == LYZ_MOD_ADDITIVE) {
			sign = 1.0;
		}

		m_coords.push_back(coord_t(point, 0.0));
		m_coords.push_back(coord_t(coord2_t(point.data[0] + width, point.data[1]), 0.0));
		m_coords.push_back(coord_t(coord2_t(point.data[0] + width, point.data[1] + sign * height), 0.0));
		m_coords.push_back(coord_t(coord2_t(point.data[0], point.data[1] + sign * height), 0.0));
	}
	
	Rectangle::~Rectangle()
	{
	}

} }