#include "graphics/pyramid.h"

namespace lyz { namespace graphics {

	Pyramid::Pyramid(float x, float y, float z, float height, float baselength)
	{
		m_sides[0] = new Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);	// left side
		m_sides[0]->setCoords(std::vector<coord_t>{
			LYZ_COORD(x,						y,				z					),
			LYZ_COORD(x - 0.5f * baselength,	y - height,		z - 0.5f * baselength),
			LYZ_COORD(x - 0.5f * baselength,	y - height,		z + 0.5f * baselength)
		});

		m_sides[1] = new Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);	// right side
		m_sides[1]->setCoords(std::vector<coord_t>{
			LYZ_COORD(x,						y,				z					),
			LYZ_COORD(x + 0.5f * baselength,	y - height,		z - 0.5f * baselength),
			LYZ_COORD(x + 0.5f * baselength,	y - height,		z + 0.5f * baselength)
		});

		m_sides[2] = new Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);	// near side
		m_sides[2]->setCoords(std::vector<coord_t>{
			LYZ_COORD(x,						y,				z					),
			LYZ_COORD(x + 0.5f * baselength,	y - height,		z + 0.5f * baselength),
			LYZ_COORD(x - 0.5f * baselength,	y - height,		z + 0.5f * baselength)
		});

		m_sides[3] = new Triangle(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);	// far side
		m_sides[3]->setCoords(std::vector<coord_t>{
			LYZ_COORD(x,						y,				z					),
			LYZ_COORD(x + 0.5f * baselength,	y - height,		z - 0.5f * baselength),
			LYZ_COORD(x - 0.5f * baselength,	y - height,		z - 0.5f * baselength)
		});

		m_bottom = new Rectangle(0.0f, 0.0f, 0.0f, 0.0f);
		m_bottom->setCoords(std::vector<coord_t>{
			LYZ_COORD(x - 0.5f * baselength, y - height, z - 0.5f * baselength),
			LYZ_COORD(x + 0.5f * baselength, y - height, z - 0.5f * baselength),
			LYZ_COORD(x + 0.5f * baselength, y - height, z + 0.5f * baselength),
			LYZ_COORD(x - 0.5f * baselength, y - height, z + 0.5f * baselength)
		});
	}

	Pyramid::Pyramid(const math::vec3 & v, float height, float baselength):
		Pyramid(v.data[0], v.data[1], v.data[2], height, baselength)
	{
	}

	Pyramid::Pyramid(float x, float y, float z, float height):
		Pyramid(x, y, z, height, height * sqrtf(2.0f))
	{
	}

	Pyramid::Pyramid(const math::vec3 & v, float height):
		Pyramid(v.data[0], v.data[1], v.data[2], height)
	{
	}

	Pyramid::~Pyramid()
	{
		for (unsigned i = 0; i < 4; ++i) {
			delete m_sides[i];
		}
		delete m_bottom;
	}

	void Pyramid::setColor(const color_t & color)
	{
		for (unsigned i = 0; i < 4; ++i) {
			m_sides[i]->setColor(color);
		}
		m_bottom->setColor(color);
	}

	void Pyramid::setColor(const color3_t & color)
	{
		setColor({ color, 1.0f });
	}

	void Pyramid::setTexture(const Texture * texture)
	{
		for (unsigned i = 0; i < 4; ++i) {
			m_sides[i]->setTexture(texture);
		}
		m_bottom->setTexture(texture);
	}

	void Pyramid::unsetTexture()
	{
		for (unsigned i = 0; i < 4; ++i) {
			m_sides[i]->unsetTexture();
		}
		m_bottom->unsetTexture();
	}

	void Pyramid::noFill(bool fill)
	{
		for (unsigned i = 0; i < 4; ++i) {
			m_sides[i]->noFill(fill);
		}
		m_bottom->noFill(fill);
	}

	std::vector<const Renderable*> Pyramid::getSubRenderables() const
	{
		std::vector<const Renderable*> subRenderables;

		for (unsigned i = 0; i < 4; ++i) {
			subRenderables.push_back(m_sides[i]);
		}	subRenderables.push_back(m_bottom);

		return subRenderables;
	}

	void lyz::graphics::Pyramid::translate(float x, float y, float z)
	{
		for (unsigned i = 0; i < 4; ++i) {
			m_sides[i]->translate(x, y, z);
		}
		m_bottom->translate(x, y, z);
	}

	void lyz::graphics::Pyramid::scale(float xfactor, float yfactor, float zfactor)
	{
		for (unsigned i = 0; i < 4; ++i) {
			m_sides[i]->translate(xfactor, yfactor, zfactor);
		}
		m_bottom->translate(xfactor, yfactor, zfactor);
	}

	void lyz::graphics::Pyramid::scale(float factor)
	{
		scale(factor, factor, factor);
	}

	void lyz::graphics::Pyramid::rotate(float angle, const coord_t & axis)
	{
		for (unsigned i = 0; i < 4; ++i) {
			m_sides[i]->rotate(angle, axis);
		}
		m_bottom->rotate(angle, axis);
	}

} }