#include "graphics/oval.h"

namespace lyz { namespace graphics {

	Oval::Oval(float x, float y, float z, float xradius, float yradius):
		m_center(math::vec3(x, y, z)), m_xradius(xradius), m_yradius(yradius)
	{
		if (m_xradius <= 0.0f || m_yradius <= 0.0f) {
			std::cerr << "ERROR[circle]: Radius have to be more than 0!\n";
			assert(false);
		}

		m_nVertices = getOptimizedNVertices();
		m_type = RenderableType::OTHER;

		construct();
	}
	
	Oval::Oval(const math::vec3 & center, float xradius, float yradius):
		Oval(center.data[0], center.data[1], center.data[2], xradius, yradius)
	{
	}
	
	Oval::Oval(float x, float y, float xradius, float yradius):
		Oval(x, y, 0.0, xradius, yradius)
	{
	}
	
	Oval::Oval(const math::vec2 & center, float xradius, float yradius):
		Oval(center.data[0], center.data[1], xradius, yradius)
	{
	}
	
	Oval::~Oval()
	{
	}
	
	void Oval::setSmoothness(float level)
	{
		setNVertices(static_cast<int>(level * static_cast<float>(getOptimizedNVertices())));
	}
	
	void Oval::setNVertices(unsigned nvertices)
	{
		m_nVertices = nvertices;
		if (m_nVertices < 3) {
			std::cout << "WARNING[Oval]: # of vertices cannot be less than 3!\n";
			m_nVertices = 3;
		}

		construct();
	}

	unsigned Oval::getOptimizedNVertices() const
	{
		return static_cast<unsigned>(50.0f * (m_xradius + m_yradius) / 2.0);
	}

	void Oval::construct()
	{
		if (!m_coords.empty()) {
			m_coords.clear();
		}

		math::vec3 vertex;
		float radius = 0.0;
		float base_radian = math::to_radians(360.0f / static_cast<float>(m_nVertices));
		float radian = 0.0;

		for (unsigned i = 0; i < m_nVertices; ++i) {
			radian = base_radian * static_cast<float>(i);
			radius = m_xradius * m_yradius / (sqrtf(powf(m_xradius * sinf(radian), 2.0f) + powf(m_yradius * cosf(radian), 2.0f)));
			
			vertex.data[0] = m_center.data[0] + radius * cosf(radian);
			vertex.data[1] = m_center.data[1] + radius * sinf(radian);
			vertex.data[2] = m_center.data[2];

			//std::cout << vertex << '\n';

			m_coords.push_back(vertex);
		}
		//assert(false);
	}

} }