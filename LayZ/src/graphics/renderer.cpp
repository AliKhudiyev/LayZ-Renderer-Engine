#include "graphics/renderer.h"

#include <algorithm>

namespace lyz { namespace graphics {

	Renderer* Renderer::renderer = nullptr;
	Shader* Renderer::shader = nullptr;

	Renderer::Renderer():
		m_vertexArray(new VertexArray()),
		m_vertexBuffer(new VertexBuffer()),
		m_indexBuffer(new IndexBuffer()), m_indexBufferLine(new IndexBuffer()), m_indexBufferPoint(new IndexBuffer()),

		m_indices(new unsigned[LYZ_RENDERER_MAX_INDICES]),
		m_indicesLine(new unsigned[LYZ_RENDERER_MAX_LINES * 2]),
		m_indicesPoint(new unsigned[LYZ_RENDERER_MAX_POINTS])
	{
		m_transformations.push_back(math::mat4::identity());
		Renderer::shader = new Shader("src/shaders/vertex.glsl", "src/shaders/fragment.glsl");
		init();
	}
	
	Renderer::~Renderer()
	{
		delete m_vertexArray;
		delete m_vertexBuffer;
		delete m_indexBuffer, m_indexBufferLine, m_indexBufferPoint;

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

	void Renderer::addTransformation(const math::mat4 & transformation)
	{
		auto last = m_transformations.back();
		m_transformations.push_back(transformation * last);
	}

	void Renderer::setTransformation(const math::mat4 & transformation)
	{
		m_transformations.push_back(transformation);
	}

	math::mat4 Renderer::popTransformation()
	{
		if (m_transformations.size() == 1) {
			std::cout << "WARNING: Trying to pop identity transformation!\n";
			return math::mat4();
		}
		auto last = m_transformations.back();
		m_transformations.pop_back();
		return last;
	}

	void Renderer::store(const Renderable* renderable)
	{
		setStoreStatus(LYZ_RENDERER_STORE_START);
		
		const auto& coords = renderable->getCoords();
		const auto& color = renderable->getColor();
		const auto& texCoords = renderable->getTextureCoords();
		const auto& texID = renderable->getTextureID();

		int texSlot = -1;
		auto index = std::find(m_texIDs.cbegin(), m_texIDs.cend(), texID);

		if (texID != -1 && index != m_texIDs.cend()) {
			texSlot = index - m_texIDs.cbegin();
		}
		else if (texID != -1) {
			texSlot = m_texIDs.size();
			m_texIDs.push_back(texID);

			LYZ_CALL(glActiveTexture(GL_TEXTURE0 + texSlot));
			LYZ_CALL(glBindTexture(GL_TEXTURE_2D, texID));
		}

		for (size_t i = 0; i < coords.size(); ++i) {
			m_vertexData->coord = coords[i];
			m_vertexData->color = color;
			m_vertexData->texCoord = coord2_t(0.0, 0.0);
			if (texCoords.size()) {
				m_vertexData->texCoord = texCoords[i];
			}
			m_vertexData->texSlot = static_cast<slot_t>(texSlot);
			++m_vertexData;
		}

		if (renderable->getType() == RenderableType::OTHER) {
		
			for (unsigned i = m_indexCount, j = m_vertexCount; i < m_indexCount + 3 * (coords.size() - 2); i += 3, ++j) {
				m_indices[i + 0] = m_vertexCount;
				m_indices[i + 1] = j + 1;
				m_indices[i + 2] = j + 2;
			}

			m_indexCount += 3 * (coords.size() - 2);
		}
		else if (renderable->getType() == RenderableType::LINE) {
			for (unsigned i = m_indexCountLine, j = m_vertexCount; i < m_indexCountLine + 2; i += 2) {
				m_indicesLine[i + 0] = j + 0;
				m_indicesLine[i + 1] = j + 1;
			}
			
			m_indexCountLine += 2;
		}
		else { // renderable->getType() == RenderableType::POINT
			for (unsigned i = m_indexCountPoint, j = m_vertexCount; i < m_indexCountPoint + 1; ++i) {
				m_indicesPoint[i] = j;
			}

			++m_indexCountPoint;
		}

		m_vertexCount += coords.size();
	}
	
	void Renderer::draw()
	{
		setStoreStatus(LYZ_RENDERER_STORE_STOP);
	
		m_indexBuffer->enable();
		m_indexBuffer->setData(m_indices, sizeof(unsigned) * m_indexCount);
		
		m_indexBufferLine->enable();
		m_indexBufferLine->setData(m_indicesLine, sizeof(unsigned) * m_indexCountLine);
		
		m_indexBufferPoint->enable();
		m_indexBufferPoint->setData(m_indicesPoint, sizeof(unsigned) * m_indexCountPoint);

		m_vertexArray->enable();
		m_indexBuffer->enable();
		Renderer::shader->enable();
		Renderer::shader->setUniform("model", m_transformations.back());

		/*for (unsigned i = 0; i < m_indexCount; ++i) {
			std::cout << m_indices[i] << " ";
		}std::cout << '\n';
		for (unsigned i = 0; i < m_indexCountLine; ++i) {
			std::cout << m_indicesLine[i] << " ";
		}std::cout << '\n';

		assert(false);*/

		LYZ_CALL(glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, nullptr));
		
		m_indexBufferLine->enable();
		LYZ_CALL(glDrawElements(GL_LINES, m_indexCountLine, GL_UNSIGNED_INT, nullptr));
		
		m_indexBufferPoint->enable();
		LYZ_CALL(glDrawElements(GL_POINTS, m_indexCountPoint, GL_UNSIGNED_INT, nullptr));

		Renderer::shader->disable();
		m_indexBuffer->disable();
		m_vertexArray->disable();
		
		m_vertexCount = 0; m_indexCountLine = 0, m_indexCountPoint = 0;
		m_indexCount = 0;
		m_texIDs.clear();
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
			LYZ_VERTEX_COLOR_ELEMENTS,
			LYZ_VERTEX_TEXTURE_ELEMENTS,
			LYZ_VERTEX_SLOT_ELEMENTS
		});

		int slots[32];
		for (int i = 0; i < 32; ++i) {
			slots[i] = i;
		}
		
		Renderer::shader->enable();
		Renderer::shader->setUniform("textures", slots, 32);
	}

} }