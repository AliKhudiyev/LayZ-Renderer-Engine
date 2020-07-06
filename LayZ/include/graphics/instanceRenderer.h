#pragma once

#include "graphics/renderer.h"

namespace lyz { namespace graphics {

	class InstanceRenderer : public Renderer {
	private:
		std::vector<const Renderable*> m_renderables;

		static InstanceRenderer* renderer;
		static Shader* shader;

	private:
		InstanceRenderer();

	public:
		~InstanceRenderer();

		static InstanceRenderer* getRenderer();

		void loadShader(const char* vertexpath, const char* fragmentpath) override;
		void loadShader(const char* shaderpath, ShaderType type) override;
		void store(const Renderable* renderable) override;
		void draw() override;
	};

} }
