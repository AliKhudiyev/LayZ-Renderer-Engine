#include "graphics/circle.h"

namespace lyz { namespace graphics {

	Circle::Circle(float x, float y, float z, float radius):
		m_center(math::vec3(x, y, z)), m_radius(radius)
	{
		m_nVertices = getOptimizedNVertices();
		m_type = RenderableType::OTHER;

		construct();
	}
	
	Circle::Circle(const math::vec3 & center, float radius):
		Circle(center.data[0], center.data[1], center.data[2], radius)
	{
	}
	
	Circle::Circle(float x, float y, float radius):
		Circle(x, y, 0.0, radius)
	{
	}
	
	Circle::Circle(const math::vec2 & center, float radius):
		Circle(center.data[0], center.data[1], radius)
	{
	}
	
	Circle::~Circle()
	{
	}
	
	void Circle::setSmoothness(float level)
	{
		setNVertices(static_cast<int>(level * static_cast<float>(getOptimizedNVertices())));
	}
	
	void Circle::setNVertices(unsigned nvertices)
	{
		m_nVertices = nvertices;
		if (m_nVertices < 3) {
			std::cout << "WARNING[circle]: # of vertices cannot be less than 3!\n";
			m_nVertices = 3;
		}

		construct();
	}

	unsigned Circle::getOptimizedNVertices() const
	{
		return static_cast<unsigned>(50.0f * m_radius);
	}

	void Circle::construct()
	{
		if (!m_coords.empty()) {
			m_coords.clear();
		}

		math::vec3 vertex;
		float radian = math::to_radians(360.0f / static_cast<float>(m_nVertices));

		for (unsigned i = 0; i < m_nVertices; ++i) {
			vertex.data[0] = m_center.data[0] + m_radius * cosf(radian * static_cast<float>(i));
			vertex.data[1] = m_center.data[1] + m_radius * sinf(radian * static_cast<float>(i));
			vertex.data[2] = m_center.data[2];

			//std::cout << vertex << '\n';

			m_coords.push_back(vertex);
		}
		//assert(false);
	}

} }