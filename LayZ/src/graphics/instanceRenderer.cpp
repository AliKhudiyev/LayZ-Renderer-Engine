#include "graphics/instanceRenderer.h"

namespace lyz {	namespace graphics {

	InstanceRenderer* InstanceRenderer::renderer = nullptr;
	Shader* InstanceRenderer::shader = nullptr;

	InstanceRenderer::InstanceRenderer()
	{
		InstanceRenderer::shader = new Shader("src/shaders/vertex.glsl", "src/shaders/fragment.glsl");
	}

	InstanceRenderer::~InstanceRenderer()
	{
		delete InstanceRenderer::renderer;
		delete InstanceRenderer::shader;
	}

	InstanceRenderer * lyz::graphics::InstanceRenderer::getRenderer()
	{
		if (!InstanceRenderer::renderer) {
			InstanceRenderer::renderer = new InstanceRenderer();
		}
		return InstanceRenderer::renderer;
	}

	void InstanceRenderer::loadShader(const char * vertexpath, const char * fragmentpath)
	{
		InstanceRenderer::shader->load(vertexpath, fragmentpath);
	}

	void InstanceRenderer::loadShader(const char * shaderpath, ShaderType type)
	{
		InstanceRenderer::shader->load(shaderpath, type);
	}

	void InstanceRenderer::store(const Renderable* renderable) {
		m_renderables.push_back(renderable);
	}

	void InstanceRenderer::draw() {
		auto batchRenderer = Renderer::renderer;
		auto batchShader = Renderer::shader;

		Renderer::shader = InstanceRenderer::shader;

		for (const auto& renderable : m_renderables) {
			batchRenderer->store(renderable);
			batchRenderer->draw();
		}

		Renderer::shader = batchShader;
	}

} }

