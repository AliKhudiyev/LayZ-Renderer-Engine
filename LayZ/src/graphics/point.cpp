#include "graphics/point.h"

namespace lyz { namespace graphics {

	float Point::pointSize = 1.0f;
	bool Point::pointType = LYZ_POINT_SQUARE;

	Point::Point(float x, float y, float z, float size)
	{
		Point::pointSize = size;

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
		Point::pointSize = size;

		LYZ_CALL(glPointSize(Point::pointSize));
	}
	
	void Point::makeCircular(bool isCircular)
	{
		Point::pointType = isCircular;

		std::cout << "WARNING[point type]: Circular point type might not be supported by GPU!\n";
		return ;

		if (Point::pointType == LYZ_POINT_CIRCULAR) {
			LYZ_CALL(glEnable(GL_POINT_SMOOTH));
		}
		else {
			LYZ_CALL(glDisable(GL_POINT_SMOOTH));
		}
	}

	void Point::setDepth(float depth)
	{
		m_coords[0].data[2] = depth;
	}

} }