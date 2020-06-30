#pragma once

#include "graphics/renderer.h"

namespace lyz { namespace graphics {

	class InstanceRenderer : public Renderer {
	private:
		std::vector<const Renderable*> m_renderables;

		static InstanceRenderer* renderer;

	private:
		InstanceRenderer() = default;

	public:
		static InstanceRenderer* getRenderer();

		void store(const Renderable* renderable) override;
		void draw() override;
	};

} }
