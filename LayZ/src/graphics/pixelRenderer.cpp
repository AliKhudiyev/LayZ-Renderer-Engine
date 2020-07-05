#include "graphics/pixelRenderer.h"

namespace lyz { namespace graphics {
	
	PixelRenderer* PixelRenderer::renderer = nullptr;

	PixelRenderer::PixelRenderer():
		m_shader(new Shader("src/shaders/vertex.glsl", "src/shaders/fragment.glsl"))
	{
	}

	PixelRenderer::PixelRenderer(unsigned width, unsigned height):
		m_width(width), m_height(height),
		m_pixelWidth(1.f), m_pixelHeight(static_cast<float>(height) / width),

		m_shader(new Shader("src/shaders/vertex.glsl", "src/shaders/fragment.glsl"))
	{
		m_pixels.resize(width * height);

		//m_pixelWidth = 2.0 / (width - 1.0);
		//m_pixelHeight = 2.0 / (height - 1.0);
		std::cout << m_pixelWidth << ", " << m_pixelHeight << '\n';

		for (unsigned i = 0; i < height; ++i) {
			for (unsigned j = 0; j < width; ++j) {
				m_pixels[i * width + j] = new Rectangle(LYZ_COORD2(m_pixelWidth * j, m_pixelHeight * i), m_pixelWidth, m_pixelHeight);
			}
		}
	}

	PixelRenderer::~PixelRenderer()
	{
		delete m_shader;
	}
	
	PixelRenderer * PixelRenderer::getRenderer(unsigned width, unsigned height)
	{
		if (!PixelRenderer::renderer) {
			PixelRenderer::renderer = new PixelRenderer(width, height);
		}
		return PixelRenderer::renderer;
	}

	void PixelRenderer::setShader(const char * vertexpath, const char * fragmentpath)
	{
		m_shader->load(vertexpath, fragmentpath);
	}
	
	void PixelRenderer::draw()
	{
		auto batchRenderer = Renderer::getRenderer();
		auto batchShader = batchRenderer->getShader();
		batchRenderer->setShader(m_shader);

		m_shader->enable();
		m_shader->setUniform("model", 
			math::mat4::ortho(
				0.f, static_cast<float>(m_width), 
				static_cast<float>(m_height), 0.f, 
				-1.f, 1.f
			)
		);

		/*auto transform = math::mat4::ortho(
			0.f, static_cast<float>(m_width),
			static_cast<float>(m_height), 0.f,
			-1.f, 1.f
		);
		std::cout << transform << '\n';
		assert(false);*/

		for (const auto& pixel : m_pixels) {
			batchRenderer->store(pixel);
		}
		batchRenderer->draw();

		batchRenderer->setShader(batchShader);
	}
	
	void PixelRenderer::setPixelWidth(float width)
	{
		float scale = static_cast<float>(m_width) / m_height;
		m_pixelWidth = width;
		m_pixelHeight = width / scale;

		updatePixels();
	}

	void PixelRenderer::setPixelHeight(float height)
	{
		float scale = static_cast<float>(m_width) / m_height;
		m_pixelHeight = height;
		m_pixelWidth = height * scale;

		updatePixels();
	}

	void PixelRenderer::setPixelAt(unsigned x, unsigned y, const color_t & color)
	{
		if (x + y * m_width >= m_width * m_height) {
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
		if (x + y * m_width >= m_width * m_height) {
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
		if (x + y * m_width >= m_width * m_height) {
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
		for (unsigned i = 0; i < m_height; ++i) {
			for (unsigned j = 0; j < m_width; ++j) {
				m_pixels[i * m_width + j]->setCoordAt(0, LYZ_COORD2(-1 + m_pixelWidth * j, 1 - m_pixelHeight * i));
				m_pixels[i * m_width + j]->setCoordAt(1, LYZ_COORD2(-1 + m_pixelWidth * j + m_pixelWidth, 1 - m_pixelHeight * i));
				m_pixels[i * m_width + j]->setCoordAt(2, LYZ_COORD2(-1 + m_pixelWidth * j + m_pixelWidth, 1 - m_pixelHeight * i - m_pixelHeight));
				m_pixels[i * m_width + j]->setCoordAt(3, LYZ_COORD2(-1 + m_pixelWidth * j, 1 - m_pixelHeight * i - m_pixelHeight));
			}
		}
	}

} }