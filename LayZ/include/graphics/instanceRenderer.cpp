#include "instanceRenderer.h"

namespace lyz {	namespace graphics {

	InstanceRenderer * lyz::graphics::InstanceRenderer::getRenderer()
	{
		if (!Renderer::renderer) {
			Renderer::renderer = new InstanceRenderer();
		}
		return reinterpret_cast<InstanceRenderer*>(Renderer::renderer);
	}

} }

