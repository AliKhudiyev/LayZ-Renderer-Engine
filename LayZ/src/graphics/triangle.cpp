#include "graphics/triangle.h"

namespace lyz { namespace graphics {

	Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3)
	{
		m_coords.push_back(coord2_t(x1, y1));
		m_coords.push_back(coord2_t(x2, y2));
		m_coords.push_back(coord2_t(x3, y3));
	}

	Triangle::Triangle(const coord2_t & v1, const coord2_t & v2, const coord2_t & v3):
		Triangle(v1.data[0], v1.data[1], v2.data[0], v2.data[1], v3.data[0], v3.data[1])
	{
	}

	Triangle::Triangle(float x, float y, float baselength, float sidelength)
	{
		// Isosceles triangle

		float h = sqrtf(powf(sidelength, 2.0) - powf(baselength / 2.0, 2.0));
		float sin_beta = sqrtf(1 - powf(baselength, 2.0) / powf(2 * sidelength, 2.0));
		float m1 = sqrtf(powf(baselength, 2.0) / 2.0 + powf(sidelength / 2.0, 2.0));
		float n = 0.5 * tanf(asinf(sin_beta * sidelength / (2.0 * m1))) * baselength;
		float m = h - n;

		m_coords.push_back(coord2_t(x, y + m));
		m_coords.push_back(coord2_t(x + baselength / 2.0, y - n));
		m_coords.push_back(coord2_t(x - baselength / 2.0, y - n));
	}
	
	Triangle::Triangle(const coord2_t & center, float baselength, float sidelength):
		Triangle(center.data[0], center.data[1], baselength, sidelength)
	{
	}

	Triangle::Triangle(float x, float y, float length)
	{
		// Equilateral triangle

		m_coords.push_back(coord2_t(x, y + length / sqrtf(3)));
		m_coords.push_back(coord2_t(x + length / 2.0, y - length / sqrtf(12)));
		m_coords.push_back(coord2_t(x - length / 2.0, y - length / sqrtf(12)));
	}

	Triangle::Triangle(const coord2_t & center, float length):
		Triangle(center.data[0], center.data[1], length)
	{
	}
	
	Triangle::~Triangle()
	{
	}

} }