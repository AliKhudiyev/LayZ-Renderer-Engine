#pragma once

#include "graphics/renderer.h"

namespace lyz { namespace graphics {

	class InstanceRenderer : public Renderer {
	private:
		std::vector<const Renderable*> m_renderables;

	private:
		InstanceRenderer() = default;

	public:
		static InstanceRenderer* getRenderer();
	};

} }
