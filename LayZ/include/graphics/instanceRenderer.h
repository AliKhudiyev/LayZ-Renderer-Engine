#pragma once

#include "graphics/renderer.h"

namespace lyz { namespace graphics {

	class InstanceRenderer : public Renderer {
	private:
		std::vector<const Renderable*> m_renderables;

		static InstanceRenderer* renderer;

		// Shader* m_shaders[LYZ_RENDERER_MAX_SHADERS];
		Shader* m_shader; // contains only vertex and fragment shaders

	private:
		InstanceRenderer();

	public:
		~InstanceRenderer();

		static InstanceRenderer* getRenderer();

		void setShader(const char* vertexpath, const char* fragmentpath);
		void store(const Renderable* renderable) override;
		void draw() override;
	};

} }
