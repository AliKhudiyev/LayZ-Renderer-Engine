#include "graphics/renderer.h"

namespace lyz { namespace graphics {

	Renderer* Renderer::renderer = nullptr;
	Shader* Renderer::shader = nullptr;

	Renderer::Renderer():
		m_vertexArray(new VertexArray()),
		m_vertexBuffer(new VertexBuffer()),
		m_indexBuffer(new IndexBuffer()),

		m_indices(new unsigned[LYZ_RENDERER_MAX_INDICES])
	{
		Renderer::shader = new Shader("src/shaders/vertex.glsl", "src/shaders/fragment.glsl");
		init();
	}
	
	Renderer::~Renderer()
	{
		delete m_vertexArray;
		delete m_vertexBuffer;
		delete m_indexBuffer;

		delete[] m_indices;

		delete Renderer::renderer;
		delete Renderer::shader;
	}

	Renderer * Renderer::getRenderer()
	{
		if (!Renderer::renderer) {
			Renderer::renderer = new Renderer();
		}
		return Renderer::renderer;
	}
	
	void Renderer::loadShader(const char * vertexpath, const char * fragmentpath)
	{
		Renderer::shader->load(vertexpath, fragmentpath);
	}

	void Renderer::loadShader(const char * shaderpath, ShaderType type)
	{
		Renderer::shader->load(shaderpath, type);
	}

	void Renderer::store(const Renderable* renderable)
	{
		setStoreStatus(LYZ_RENDERER_STORE_START);
		
		const auto& coords = renderable->getCoords();
		const auto& color = renderable->getColor();

		for (const auto coord : coords) {
			m_vertexData->coord = coord;
			m_vertexData->color = color;
			++m_vertexData;
		}
		
		for (unsigned i = m_indexCount, j = m_vertexCount; i < m_indexCount + 3 * (coords.size() - 2); i += 3, ++j) {
			m_indices[i + 0] = m_vertexCount;
			m_indices[i + 1] = j + 1;
			m_indices[i + 2] = j + 2;
		}

		m_vertexCount += coords.size();
		m_indexCount += 3 * (coords.size() - 2);
	}
	
	void Renderer::draw()
	{
		setStoreStatus(LYZ_RENDERER_STORE_STOP);
	
		m_indexBuffer->setData(m_indices, sizeof(unsigned) * m_indexCount);

		m_vertexArray->enable();
		m_indexBuffer->enable();
		Renderer::shader->enable();

		LYZ_CALL(glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, nullptr));

		Renderer::shader->disable();
		m_indexBuffer->disable();
		m_vertexArray->disable();
		
		m_vertexCount = 0;
		m_indexCount = 0;
	}

	void Renderer::clear()
	{
		LYZ_CALL(glClear(GL_COLOR_BUFFER_BIT));
	}

	void Renderer::setStoreStatus(renderer_status_t status)
	{
		if (status == m_rendererStatus) return;
		m_rendererStatus = status;

		if (status == LYZ_RENDERER_STORE_START) {
			m_vertexBuffer->enable();
			LYZ_CALL(m_vertexData = reinterpret_cast<VertexData*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY)));
		}
		else {
			LYZ_CALL(glUnmapBuffer(GL_ARRAY_BUFFER));
			m_vertexBuffer->disable();
		}
	}

	void Renderer::init()
	{
		m_vertexBuffer->setData(nullptr, LYZ_RENDERER_MAX_VERTICES_SIZE);
		m_vertexBuffer->setLayout({
			LYZ_VERTEX_COORD_ELEMENTS,
			LYZ_VERTEX_COLOR_ELEMENTS
		});
	}

} }