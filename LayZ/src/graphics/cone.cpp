#include "graphics/cone.h"

namespace lyz { namespace graphics {

	Cone::Cone(float x, float y, float z, float radius, float height):
		m_center(math::vec3(x, y, z)), m_xradius(radius), m_yradius(radius), m_height(height),
		m_bottom(nullptr)
	{
		m_nVertices = getOptimizedNVertices();

		construct();
	}
	
	Cone::Cone(const math::vec3 & v, float radius, float height) :
		Cone(v.data[0], v.data[1], v.data[2], radius, height)
	{
	}
	
	Cone::~Cone()
	{
		for (auto& side : m_sides) {
			delete side;
		}	delete m_bottom;
	}

	void Cone::setXRadius(float radius)
	{
		m_xradius = radius;

		construct();
	}

	void Cone::setYRadius(float radius)
	{
		m_yradius = radius;

		construct();
	}

	void Cone::setSmoothness(float smoothness)
	{
		setNVertices(static_cast<unsigned>(smoothness * static_cast<float>(getOptimizedNVertices())));
	}

	void Cone::setNVertices(unsigned nvertices)
	{
		m_nVertices = nvertices;

		construct();
	}
	
	void Cone::setColor(const color_t & color)
	{
		for (const auto& side : m_sides) {
			side->setColor(color);
		}	m_bottom->setColor(color);
	}
	
	void Cone::setColor(const color3_t & color)
	{
		setColor({ color, 1.0f });
	}

	void Cone::setTexture(const Texture * texture)
	{
		for (const auto& side : m_sides) {
			side->setTexture(texture);
		}	m_bottom->setTexture(texture);
	}

	void Cone::unsetTexture()
	{
		for (const auto& side : m_sides) {
			side->unsetTexture();
		}	m_bottom->unsetTexture();
	}

	void Cone::noFill(bool fill)
	{
		for (const auto& side : m_sides) {
			side->noFill(fill);
		}	m_bottom->noFill(fill);
	}
	
	std::vector<const Renderable*> Cone::getSubRenderables() const
	{
		std::vector<const Renderable*> subRenderables;

		for (const auto& side : m_sides) {
			subRenderables.push_back(side);
		}	subRenderables.push_back(m_bottom);

		return subRenderables;
	}

	void Cone::translate(float x, float y, float z)
	{
		for (const auto& side : m_sides) {
			side->translate(x, y, z);
		}	m_bottom->translate(x, y, z);
	}

	void Cone::scale(float xfactor, float yfactor, float zfactor)
	{
		for (const auto& side : m_sides) {
			side->scale(xfactor, yfactor, zfactor);
		}	m_bottom->scale(xfactor, yfactor, zfactor);
	}

	void Cone::scale(float factor)
	{
		scale(factor, factor, factor);
	}

	void Cone::rotate(float angle, const coord_t & axis)
	{
		for (const auto& side : m_sides) {
			side->rotate(angle, axis);
		}	m_bottom->rotate(angle, axis);
	}

	unsigned Cone::getOptimizedNVertices() const
	{
		return 10;
	}

	void Cone::construct()
	{
		m_sides.clear();
		delete m_bottom;	m_bottom = nullptr;

		m_bottom = new Oval(0.0f, 0.0f, m_xradius, m_yradius);
		m_bottom->setNVertices(m_nVertices);
		m_bottom->rotate(90.0f, math::vec3(1.0f, 0.0f, 0.0f));
		m_bottom->translate(m_center.data[0], m_center.data[1], m_center.data[2]);

		const auto& coords = m_bottom->getCoords();

 		for (unsigned i = 0; i < m_nVertices; ++i) {
			auto triangle = new Triangle(0.0f, 0.0f, 0.0f, 1.0f);
			triangle->setCoords(std::vector<coord_t>{
				LYZ_COORD(m_center.data[0], m_center.data[1] + m_height, m_center.data[2]),
				coords[i],
				coords[(i + 1) % m_nVertices]
			});

			m_sides.push_back(triangle);
		}
	}

} }