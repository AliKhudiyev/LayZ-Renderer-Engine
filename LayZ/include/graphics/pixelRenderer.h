#pragma once

#include "graphics/renderer.h"
#include "graphics/rectangle.h"

namespace lyz { namespace graphics {

	class PixelRenderer : public Renderer {
	private:
		unsigned m_width, m_height;
		unsigned m_pixelWidth, m_pixelHeight;
		std::vector<Rectangle*> m_pixels;

		static PixelRenderer* renderer;
		static Shader* shader;

	private:
		PixelRenderer();
		PixelRenderer(unsigned width, unsigned height);

	public:
		~PixelRenderer();

		static PixelRenderer* getRenderer(unsigned width, unsigned height);

		void loadShader(const char* vertexpath, const char* fragmentpath) override;
		void loadShader(const char* shaderpath, ShaderType type) override;
		inline void store(const Renderable* renderable) override {}
		void draw() override;

		void setPixelWidth(unsigned width);
		void setPixelHeight(unsigned height);
		void setPixelAt(unsigned x, unsigned y, const color_t& color);
		void setPixelAt(unsigned index, const color_t& color);
		void setPixelAt(unsigned x, unsigned y, const color3_t& color);
		void setPixelAt(unsigned index, const color3_t& color);
		const color_t& getPixelAt(unsigned x, unsigned y) const;
		const color_t& getPixelAt(unsigned index) const;
	
	private:
		void updatePixels();
	};

} }
