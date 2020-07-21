#include "graphics/renderable.h"

#include "utils/utils.h"

namespace lyz { namespace graphics {

	Renderable::Renderable(const std::vector<coord_t>& coords):
		m_coords(coords), m_texture(nullptr)
	{
		m_texCoords.resize(coords.size());

		if (coords.size() == 1) {
			m_type = RenderableType::POINT;
		}
		else if (coords.size() == 2) {
			m_type = RenderableType::LINE;
		}
		else {
			m_type = RenderableType::OTHER;
		}
	}
	
	Renderable::Renderable(const std::vector<coord2_t>& coords):
		m_texture(nullptr)
	{
		for (const auto& coord : coords)
			m_coords.push_back(coord_t(coord, 0.0));
		m_texCoords = utils::tell_texCoords(coords);

		if (coords.size() == 1) {
			m_type = RenderableType::POINT;
		}
		else if (coords.size() == 2) {
			m_type = RenderableType::LINE;
		}
		else {
			m_type = RenderableType::OTHER;
		}
	}

	Renderable::~Renderable()
	{
	}

	void Renderable::setCoords(const std::vector<coord_t>& coords)
	{
		m_coords = coords;
		m_texCoords.resize(coords.size());

		if (coords.size() == 1) {
			m_type = RenderableType::POINT;
		}
		else if (coords.size() == 2) {
			m_type = RenderableType::LINE;
		}
		else {
			m_type = RenderableType::OTHER;
		}
	}

	void Renderable::setCoords(const std::vector<coord2_t>& coords)
	{
		m_coords.clear();
		for (const auto& coord : coords) {
			m_coords.push_back(coord);
		}
		m_texCoords = utils::tell_texCoords(coords);

		if (coords.size() == 1) {
			m_type = RenderableType::POINT;
		}
		else if (coords.size() == 2) {
			m_type = RenderableType::LINE;
		}
		else {
			m_type = RenderableType::OTHER;
		}
	}

	void Renderable::setCoordAt(unsigned index, const coord_t & coord)
	{
		if (index >= m_coords.size()) {
			std::cerr << "ERROR[setting coord at]: index out of boundaries!\n";
			assert(false);
		}

		m_coords[index] = coord;
	}

	void Renderable::setCoordAt(unsigned index, const coord2_t & coord)
	{
		if (index >= m_coords.size()) {
			std::cerr << "ERROR[setting coord at]: index out of boundaries!\n";
			assert(false);
		}

		m_coords[index] = coord_t(coord, 0.0);
	}
	
	void Renderable::setColor(const color_t & color)
	{
		m_color = color;
	}
	
	void Renderable::setColor(const color3_t & color)
	{
		m_color = color_t(color, 1.0);
	}

	void Renderable::setTexture(const Texture * texture)
	{
		if (!texture) {
			std::cerr << "ERROR[setting texture]: Null texture!\n";
			assert(false);
		}
		m_texture = texture;
		m_texCoords = utils::tell_texCoords(m_coords);
	}

	void Renderable::unsetTexture()
	{
		setTexture(LYZ_NO_TEXTURE);
	}

} }