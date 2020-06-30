#pragma once

#include "graphics/renderer.h"

namespace lyz { namespace graphics {

	class PixelRenderer : public Renderer {
	private:
		unsigned m_width, m_height;
		color_t* m_pixelSpace;

		math::mat4 m_transformation;

		static PixelRenderer* renderer;

	private:
		PixelRenderer() = default;
		PixelRenderer(unsigned width, unsigned height);

	public:
		~PixelRenderer();

		static PixelRenderer* getRenderer(unsigned width, unsigned height);

		inline void store(const Renderable* renderable) override {}
		void draw() override;

		void setPixelAt(unsigned x, unsigned y, const color_t& color);
		void setPixelAt(unsigned index, const color_t& color);
		void setPixelAt(unsigned x, unsigned y, const color3_t& color);
		void setPixelAt(unsigned index, const color3_t& color);
		const color_t& getPixelAt(unsigned x, unsigned y) const;
		const color_t& getPixelAt(unsigned index) const;
		void updatePixels();
	};

} }
