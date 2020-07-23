#include "graphics/cuboid.h"

namespace lyz { namespace graphics {

	Cuboid::Cuboid(float x, float y, float z, float width, float height, float depth)
	{
		m_faces[0] = new Rectangle(0.0f, 0.0f, 0.0f, 0.0f);	// left face
		m_faces[0]->setCoords(std::vector<coord_t>{
			LYZ_COORD(x,	y,				z		),
			LYZ_COORD(x,	y - height,		z		),
			LYZ_COORD(x,	y - height,		z - depth),
			LYZ_COORD(x,	y,				z - depth)
		});

		m_faces[1] = new Rectangle(0.0f, 0.0f, 0.0f, 0.0f);	// right face
		m_faces[1]->setCoords(std::vector<coord_t>{
			LYZ_COORD(x + width,	y,				z		),
			LYZ_COORD(x + width,	y - height,		z		),
			LYZ_COORD(x + width,	y - height,		z - depth),
			LYZ_COORD(x + width,	y,				z - depth)
		});

		m_faces[2] = new Rectangle(0.0f, 0.0f, 0.0f, 0.0f);	// top face
		m_faces[2]->setCoords(std::vector<coord_t>{
			LYZ_COORD(x,			y,	z		),
			LYZ_COORD(x + width,	y,	z		),
			LYZ_COORD(x + width,	y,	z - depth),
			LYZ_COORD(x,			y,	z - depth)
		});

		m_faces[3] = new Rectangle(0.0f, 0.0f, 0.0f, 0.0f);	// bottom face
		m_faces[0]->setCoords(std::vector<coord_t>{
			LYZ_COORD(x,			y - height,		z		),
			LYZ_COORD(x + width,	y - height,		z		),
			LYZ_COORD(x + width,	y - height,		z - depth),
			LYZ_COORD(x,			y - height,		z - depth)
		});

		m_faces[4] = new Rectangle(x, y, width, height);	// near face
		m_faces[4]->setDepth(z);

		m_faces[5] = new Rectangle(x, y, width, height);	// far face
		m_faces[5]->setDepth(z - depth);
	}

	Cuboid::Cuboid(const math::vec3 & v, float width, float height, float depth):
		Cuboid(v.data[0], v.data[1], v.data[2], width, height, depth)
	{
	}

	Cuboid::~Cuboid()
	{
		for (unsigned i = 0; i < 6; ++i) {
			delete m_faces[i];
		}
	}

	void lyz::graphics::Cuboid::setColor(const color_t & color)
	{
		for (unsigned i = 0; i < 6; ++i) {
			m_faces[i]->setColor(color);
		}
	}

	void lyz::graphics::Cuboid::setColor(const color3_t & color)
	{
		setColor({ color, 1.0f });
	}

	void lyz::graphics::Cuboid::setTexture(const Texture * texture)
	{
		for (unsigned i = 0; i < 6; ++i) {
			m_faces[i]->setTexture(texture);
		}
	}

	void lyz::graphics::Cuboid::unsetTexture()
	{
		for (unsigned i = 0; i < 6; ++i) {
			m_faces[i]->unsetTexture();
		}
	}

	void lyz::graphics::Cuboid::noFill(bool fill)
	{
		for (unsigned i = 0; i < 6; ++i) {
			m_faces[i]->noFill(fill);
		}
	}

	std::vector<const Renderable*> lyz::graphics::Cuboid::getSubRenderables() const
	{
		std::vector<const Renderable*> subRenderables;
		
		for (unsigned i = 0; i < 6; ++i) {
			subRenderables.push_back(m_faces[i]);
		}

		return subRenderables;
	}

	void Cuboid::translate(float x, float y, float z)
	{
		for (unsigned i = 0; i < 6; ++i) {
			m_faces[i]->translate(x, y, z);
		}
	}

	void Cuboid::scale(float xfactor, float yfactor, float zfactor)
	{
		for (unsigned i = 0; i < 6; ++i) {
			m_faces[i]->scale(xfactor, yfactor, zfactor);
		}
	}

	void Cuboid::scale(float factor)
	{
		scale(factor, factor, factor);
	}

	void Cuboid::rotate(float angle, const coord_t & axis)
	{
		for (unsigned i = 0; i < 6; ++i) {
			m_faces[i]->rotate(angle, axis);
		}
	}

} }