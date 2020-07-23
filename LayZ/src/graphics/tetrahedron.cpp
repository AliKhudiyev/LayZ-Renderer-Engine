#include "graphics/tetrahedron.h"

namespace lyz { namespace graphics {

	Tetrahedron::Tetrahedron(float x, float y, float z, float height)
	{
		float l = 8.0f * height / (3.0f * sqrtf(5.0f));
		float n = height / sqrtf(15.0f), m = sqrtf(l * l - height * height);

		m_faces[0] = new Triangle(0.0f, 0.0f, 0.0f, 1.0f);
		m_faces[0]->setCoords(std::vector<coord_t>{
			LYZ_COORD(x,		y,				z			),
			LYZ_COORD(x + m,	y - height,		z			),
			LYZ_COORD(x - n,	y - height,		z - 0.5f * l)
		});
	
		m_faces[1] = new Triangle(0.0f, 0.0f, 0.0f, 1.0f);
		m_faces[1]->setCoords(std::vector<coord_t>{
			LYZ_COORD(x,		y,				z			),
			LYZ_COORD(x + m,	y - height,		z			),
			LYZ_COORD(x - n,	y - height,		z + 0.5f * l)
		});

		m_faces[2] = new Triangle(0.0f, 0.0f, 0.0f, 1.0f);
		m_faces[2]->setCoords(std::vector<coord_t>{
			LYZ_COORD(x,		y,				z			),
			LYZ_COORD(x - n,	y - height,		z + 0.5f * l),
			LYZ_COORD(x - n,	y - height,		z - 0.5f * l)
		});

		m_faces[3] = new Triangle(0.0f, 0.0f, 0.0f, 1.0f);
		m_faces[3]->setCoords(std::vector<coord_t>{
			LYZ_COORD(x + m,	y - height,		z			),
			LYZ_COORD(x - n,	y - height,		z + 0.5f * l),
			LYZ_COORD(x - n,	y - height,		z - 0.5f * l)
		});
	}

	Tetrahedron::Tetrahedron(const math::vec3 & v, float height)
	{
		// TO DO
	}

	Tetrahedron::~Tetrahedron()
	{
		for (unsigned i = 0; i < 4; ++i) {
			delete m_faces[i];
		}
	}

	void Tetrahedron::setColor(const color_t & color)
	{
		for (unsigned i = 0; i < 4; ++i) {
			m_faces[i]->setColor(color);
		}
	}

	void Tetrahedron::setColor(const color3_t & color)
	{
		setColor({ color, 1.0f });
	}

	void lyz::graphics::Tetrahedron::setTexture(const Texture * texture)
	{
		for (unsigned i = 0; i < 4; ++i) {
			m_faces[i]->setTexture(texture);
		}
	}

	void lyz::graphics::Tetrahedron::unsetTexture()
	{
		for (unsigned i = 0; i < 4; ++i) {
			m_faces[i]->unsetTexture();
		}
	}

	void lyz::graphics::Tetrahedron::noFill(bool fill)
	{
		for (unsigned i = 0; i < 4; ++i) {
			m_faces[i]->noFill(fill);
		}
	}

	std::vector<const Renderable*> Tetrahedron::getSubRenderables() const
	{
		std::vector<const Renderable*> subRenderables;

		for (unsigned i = 0; i < 4; ++i) {
			subRenderables.push_back(m_faces[i]);
		}

		return subRenderables;
	}

	void lyz::graphics::Tetrahedron::translate(float x, float y, float z)
	{
		for (unsigned i = 0; i < 4; ++i) {
			m_faces[i]->translate(x, y, z);
		}
	}

	void lyz::graphics::Tetrahedron::scale(float xfactor, float yfactor, float zfactor)
	{
		for (unsigned i = 0; i < 4; ++i) {
			m_faces[i]->scale(xfactor, yfactor, zfactor);
		}
	}

	void lyz::graphics::Tetrahedron::scale(float factor)
	{
		scale(factor, factor, factor);
	}

	void lyz::graphics::Tetrahedron::rotate(float angle, const coord_t & axis)
	{
		for (unsigned i = 0; i < 4; ++i) {
			m_faces[i]->rotate(angle, axis);
		}
	}

} }