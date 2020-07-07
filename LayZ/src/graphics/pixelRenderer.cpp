#include "graphics/pixelRenderer.h"

namespace lyz { namespace graphics {
	
	PixelRenderer* PixelRenderer::renderer = nullptr;
	Shader* PixelRenderer::shader = nullptr;

	PixelRenderer::PixelRenderer()
	{
		PixelRenderer::shader = new Shader("src/shaders/vertex.glsl", "src/shaders/fragment.glsl");
	}

	PixelRenderer::PixelRenderer(unsigned width, unsigned height):
		m_width(width), m_height(height),
		m_pixelWidth(1), m_pixelHeight(1)
	{
		PixelRenderer::shader = new Shader("src/shaders/vertex.glsl", "src/shaders/fragment.glsl");

		m_pixels.resize(width * height);

		for (unsigned i = 0, row = 0; row < height; ++i, row += m_pixelHeight) {
			for (unsigned j = 0, col = 0; col < width; ++j, col += m_pixelWidth) {
				m_pixels[i * width + j] = new Rectangle(
					LYZ_COORD2(static_cast<float>(m_pixelWidth) * j, static_cast<float>(m_pixelHeight) * (i + 1)), 
					static_cast<float>(m_pixelWidth), static_cast<float>(m_pixelHeight)
				);
			}
		}

		PixelRenderer::shader->enable();
		PixelRenderer::shader->setUniform("model",
			math::mat4::ortho(
				0.f, static_cast<float>(m_width),
				static_cast<float>(m_height), 0.f,
				-1.f, 1.f
			)
		);
	}

	PixelRenderer::~PixelRenderer()
	{
		delete PixelRenderer::renderer;
		delete PixelRenderer::shader;
	}
	
	PixelRenderer * PixelRenderer::getRenderer(unsigned width, unsigned height)
	{
		if (!PixelRenderer::renderer) {
			PixelRenderer::renderer = new PixelRenderer(width, height);
		}
		return PixelRenderer::renderer;
	}

	void PixelRenderer::loadShader(const char * vertexpath, const char * fragmentpath)
	{
		PixelRenderer::shader->load(vertexpath, fragmentpath);
	}

	void PixelRenderer::loadShader(const char * shaderpath, ShaderType type)
	{
		PixelRenderer::shader->load(shaderpath, type);
	}
	
	void PixelRenderer::draw()
	{
		auto batchRenderer = Renderer::renderer;
		auto batchShader = Renderer::shader;

		Renderer::shader = PixelRenderer::shader;

		for (unsigned i = 0, row = 0; row < m_height; ++i, row += m_pixelHeight) {
			for (unsigned j = 0, col = 0; col < m_width; ++j, col += m_pixelWidth) {
				batchRenderer->store(m_pixels[i * m_width + j]);
			}
		}
		batchRenderer->draw();

		Renderer::shader = batchShader;
	}
	
	void PixelRenderer::setPixelWidth(unsigned width)
	{
		m_pixelWidth = width;

		updatePixels();
	}

	void PixelRenderer::setPixelHeight(unsigned height)
	{
		m_pixelHeight = height;

		updatePixels();
	}

	void PixelRenderer::setPixelAt(unsigned x, unsigned y, const color_t & color)
	{
		if (x >= m_width || y >= m_height) {
			std::cerr << "ERROR[setting pixel]: Pixel position out of pixel space!" << std::endl;
			assert(false);
		}
		m_pixels[x + y * m_width]->setColor(color);
	}
	
	void PixelRenderer::setPixelAt(unsigned index, const color_t & color)
	{
		if (index >= m_width * m_height) {
			std::cerr << "ERROR[setting pixel]: Pixel position out of pixel space!" << std::endl;
			assert(false);
		}
		m_pixels[index]->setColor(color);
	}

	void PixelRenderer::setPixelAt(unsigned x, unsigned y, const color3_t & color)
	{
		if (x >= m_width || y >= m_height) {
			std::cerr << "ERROR[setting pixel]: Pixel position out of pixel space!" << std::endl;
			assert(false);
		}
		m_pixels[x + y * m_width]->setColor(color_t(color, 1.0));
	}

	void PixelRenderer::setPixelAt(unsigned index, const color3_t & color)
	{
		if (index >= m_width * m_height) {
			std::cerr << "ERROR[setting pixel]: Pixel position out of pixel space!" << std::endl;
			assert(false);
		}
		m_pixels[index]->setColor(color_t(color, 1.0));
	}
	
	const color_t& PixelRenderer::getPixelAt(unsigned x, unsigned y) const
	{
		if (x >= m_width || y >= m_height) {
			std::cerr << "ERROR[setting pixel]: Pixel position out of pixel space!" << std::endl;
			assert(false);
		}
		return m_pixels[x + y * m_width]->getColor();
	}
	
	const color_t& PixelRenderer::getPixelAt(unsigned index) const
	{
		if (index >= m_width * m_height) {
			std::cerr << "ERROR[setting pixel]: Pixel position out of pixel space!" << std::endl;
			assert(false);
		}
		return m_pixels[index]->getColor();
	}
	
	void PixelRenderer::updatePixels()
	{
		for (unsigned i = 0, row = 0; row < m_height; ++i, row += m_pixelHeight) {
			for (unsigned j = 0, col = 0; col < m_width; ++j, col += m_pixelWidth) {
				m_pixels[i * m_width + j]->setCoordAt(0, LYZ_COORD2(static_cast<float>(m_pixelWidth) * j, static_cast<float>(m_pixelHeight) * i));
				m_pixels[i * m_width + j]->setCoordAt(1, LYZ_COORD2(static_cast<float>(m_pixelWidth) * j + static_cast<float>(m_pixelWidth), static_cast<float>(m_pixelHeight) * i));
				m_pixels[i * m_width + j]->setCoordAt(2, LYZ_COORD2(static_cast<float>(m_pixelWidth) * j + static_cast<float>(m_pixelWidth), static_cast<float>(m_pixelHeight) * i + static_cast<float>(m_pixelHeight)));
				m_pixels[i * m_width + j]->setCoordAt(3, LYZ_COORD2(static_cast<float>(m_pixelWidth) * j, static_cast<float>(m_pixelHeight) * i + static_cast<float>(m_pixelHeight)));
			}
		}
	}

} }