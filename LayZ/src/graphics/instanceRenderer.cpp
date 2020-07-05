#include "graphics/instanceRenderer.h"

namespace lyz {	namespace graphics {

	InstanceRenderer* InstanceRenderer::renderer = nullptr;

	InstanceRenderer::InstanceRenderer()
	{
		m_shader = new Shader("src/shaders/vertex.glsl", "src/shaders/fragment.glsl");
	}

	InstanceRenderer::~InstanceRenderer()
	{
		delete m_shader;
	}

	InstanceRenderer * lyz::graphics::InstanceRenderer::getRenderer()
	{
		if (!InstanceRenderer::renderer) {
			InstanceRenderer::renderer = new InstanceRenderer();
		}
		return InstanceRenderer::renderer;
	}

	void InstanceRenderer::setShader(const char * vertexpath, const char * fragmentpath)
	{
		m_shader->load(vertexpath, fragmentpath);
	}

	void InstanceRenderer::store(const Renderable* renderable) {
		m_renderables.push_back(renderable);
	}

	void InstanceRenderer::draw() {
		auto batchRenderer = Renderer::getRenderer();
		for (const auto& renderable : m_renderables)
			batchRenderer->store(renderable);
			batchRenderer->draw();
	}

} }

