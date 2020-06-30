#include "graphics/pixelRenderer.h"

namespace lyz { namespace graphics {
	
	PixelRenderer* PixelRenderer::renderer = nullptr;

	PixelRenderer::PixelRenderer(unsigned width, unsigned height):
		m_width(width), m_height(height), m_pixelSpace(new color_t[width * height])
	{
	}

	PixelRenderer::~PixelRenderer()
	{
	}
	
	PixelRenderer * PixelRenderer::getRenderer(unsigned width, unsigned height)
	{
		if (!PixelRenderer::renderer) {
			PixelRenderer::renderer = new PixelRenderer(width, height);
		}
		return PixelRenderer::renderer;
	}
	
	void PixelRenderer::draw()
	{
		// TO DO

		auto batchRenderer = Renderer::getRenderer();
		// Renderable* rects = new Renderable[m_width * m_height];
		
		for (unsigned i = 0; i < m_width; ++i) {
			for (unsigned j = 0; j < m_height; ++j) {
				std::vector<coord2_t> coords{
					LYZ_COORD2(0.0, 0.0),
					LYZ_COORD2(0.0, 0.0),
					LYZ_COORD2(0.0, 0.0),
					LYZ_COORD2(0.0, 0.0)
				};
				// batchRenderer->store(rects[i + j * m_width]);
			}
		}
		batchRenderer->draw();
	}
	
	void PixelRenderer::setPixelAt(unsigned x, unsigned y, const color_t & color)
	{
		if (x + y * m_width >= m_width * m_height) {
			std::cerr << "ERROR[setting pixel]: Pixel position out of pixel space!" << std::endl;
			assert(false);
		}
		m_pixelSpace[x + y * m_width] = color;
	}
	
	void PixelRenderer::setPixelAt(unsigned index, const color_t & color)
	{
		if (index >= m_width * m_height) {
			std::cerr << "ERROR[setting pixel]: Pixel position out of pixel space!" << std::endl;
			assert(false);
		}
		m_pixelSpace[index] = color;
	}

	void PixelRenderer::setPixelAt(unsigned x, unsigned y, const color3_t & color)
	{
		if (x + y * m_width >= m_width * m_height) {
			std::cerr << "ERROR[setting pixel]: Pixel position out of pixel space!" << std::endl;
			assert(false);
		}
		m_pixelSpace[x + y * m_width] = color_t(color, 1.0);
	}

	void PixelRenderer::setPixelAt(unsigned index, const color3_t & color)
	{
		if (index >= m_width * m_height) {
			std::cerr << "ERROR[setting pixel]: Pixel position out of pixel space!" << std::endl;
			assert(false);
		}
		m_pixelSpace[index] = color_t(color, 1.0);
	}
	
	const color_t& PixelRenderer::getPixelAt(unsigned x, unsigned y) const
	{
		if (x + y * m_width >= m_width * m_height) {
			std::cerr << "ERROR[setting pixel]: Pixel position out of pixel space!" << std::endl;
			assert(false);
		}
		return m_pixelSpace[x + y * m_width];
	}
	
	const color_t& PixelRenderer::getPixelAt(unsigned index) const
	{
		if (index >= m_width * m_height) {
			std::cerr << "ERROR[setting pixel]: Pixel position out of pixel space!" << std::endl;
			assert(false);
		}
		return m_pixelSpace[index];
	}
	
	void PixelRenderer::updatePixels()
	{
		draw();
	}

} }