#include "graphics/cylinder.h"

namespace lyz { namespace graphics {

	Cylinder::Cylinder(float x, float y, float z, float radius, float height):
		m_center(math::vec3(x, y, z)), m_xradius(radius), m_yradius(radius), m_height(height),
		m_bottom(nullptr), m_top(nullptr)
	{
		m_nVertices = getOptimizedNVertices();

		construct();
	}
	
	Cylinder::Cylinder(const math::vec3 & v, float radius, float height):
		Cylinder(v.data[0], v.data[1], v.data[2], radius, height)
	{
	}
	
	Cylinder::~Cylinder()
	{
		for (auto& side : m_sides) {
			delete side;
		}
		delete m_bottom;
		delete m_top;
	}

	void Cylinder::setXRadius(float radius)
	{
		m_xradius = m_xradius;

		construct();
	}

	void Cylinder::setYRadius(float radius)
	{
		m_yradius = m_yradius;

		construct();
	}

	void Cylinder::setSmoothness(float smoothness)
	{
		setNVertices(static_cast<unsigned>(smoothness * static_cast<float>(getOptimizedNVertices())));
	}

	void Cylinder::setNVertices(unsigned nvertices)
	{
		m_nVertices = nvertices;

		construct();
	}
	
	void Cylinder::setColor(const color_t & color)
	{
		for (auto& side : m_sides) {
			side->setColor(color);
		}
		m_bottom->setColor(color);
		m_top->setColor(color);
	}
	
	void Cylinder::setColor(const color3_t & color)
	{
		setColor({ color, 1.0f });
	}
	
	void Cylinder::setTexture(const Texture * texture)
	{
		for (auto& side : m_sides) {
			side->setTexture(texture);
		}
		m_bottom->setTexture(texture);
		m_top->setTexture(texture);
	}
	
	void Cylinder::unsetTexture()
	{
		for (auto& side : m_sides) {
			side->unsetTexture();
		}
		m_bottom->unsetTexture();
		m_top->unsetTexture();
	}
	
	void Cylinder::noFill(bool fill)
	{
		for (auto& side : m_sides) {
			side->noFill(fill);
		}
		m_bottom->noFill(fill);
		m_top->noFill(fill);
	}
	
	std::vector<const Renderable*> Cylinder::getSubRenderables() const
	{
		std::vector<const Renderable*> subRenderables;

		for (auto& side : m_sides) {
			subRenderables.push_back(side);
		}
		subRenderables.push_back(m_bottom);
		subRenderables.push_back(m_top);

		return subRenderables;
	}

	void Cylinder::translate(float x, float y, float z)
	{
		for (auto& side : m_sides) {
			side->translate(x, y, z);
		}
		m_bottom->translate(x, y, z);
		m_top->translate(x, y, z);
	}

	void Cylinder::scale(float xfactor, float yfactor, float zfactor)
	{
		for (auto& side : m_sides) {
			side->scale(xfactor, yfactor, zfactor);
		}
		m_bottom->scale(xfactor, yfactor, zfactor);
		m_top->scale(xfactor, yfactor, zfactor);
	}

	void Cylinder::scale(float factor)
	{
		scale(factor, factor, factor);
	}

	void Cylinder::rotate(float angle, const coord_t & axis)
	{
		for (auto& side : m_sides) {
			side->rotate(angle, axis);
		}
		m_bottom->rotate(angle, axis);
		m_top->rotate(angle, axis);
	}

	unsigned Cylinder::getOptimizedNVertices() const
	{
		return 10;
	}

	void Cylinder::construct()
	{
		m_sides.clear();
		delete m_bottom;	m_bottom = nullptr;
		delete m_top;		m_top = nullptr;

		m_bottom = new Oval(0.0f, 0.0f, m_xradius, m_yradius);
		m_bottom->setNVertices(m_nVertices);
		m_bottom->rotate(90.0f, math::vec3(1.0f, 0.0f, 0.0f));
		m_bottom->translate(m_center.data[0], m_center.data[1] - m_height / 2.0f, m_center.data[2]);

		m_top = new Oval(0.0f, 0.0f, m_xradius, m_yradius);
		m_top->setNVertices(m_nVertices);
		m_top->rotate(90.0f, math::vec3(1.0f, 0.0f, 0.0f));
		m_top->translate(m_center.data[0], m_center.data[1] + m_height / 2.0f, m_center.data[2]);

		const auto& bottomCoords = m_bottom->getCoords();
		const auto& topCoords = m_top->getCoords();

		for (unsigned i = 0; i < m_nVertices; ++i) {
			auto rectangle = new Rectangle(0.0f, 0.0f, 1.0f, 1.0f);
			rectangle->setCoords(std::vector<coord_t>{
				topCoords[i],
				topCoords[(i + 1) % m_nVertices],
				bottomCoords[(i + 1) % m_nVertices],
				bottomCoords[i]
			});

			m_sides.push_back(rectangle);
		}
	}

} }