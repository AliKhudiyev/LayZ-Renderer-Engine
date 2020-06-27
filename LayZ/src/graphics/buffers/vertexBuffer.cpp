#include "graphics/buffers/vertexBuffer.h"

namespace lyz { namespace graphics {

	VertexBuffer::VertexBuffer(GLvoid* data, GLsizei size)
	{
		LYZ_CALL(glGenBuffers(1, &m_ID));
		LYZ_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_ID));
		LYZ_CALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	}

	VertexBuffer::~VertexBuffer()
	{
	}

	void VertexBuffer::enable() const
	{
		LYZ_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_ID));
	}

	void VertexBuffer::disable() const
	{
		LYZ_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	void VertexBuffer::setLayout(const std::initializer_list<unsigned>& batchCounts)
	{
		unsigned totalCount = 0;
		for (const auto& count : batchCounts) {
			totalCount += count;
		}

		for (const auto& count : batchCounts) {
			LYZ_CALL(glEnableVertexAttribArray(VertexBuffer::m_indexSlot));
			LYZ_CALL(glVertexAttribPointer(VertexBuffer::m_indexSlot++, count, GL_FLOAT, GL_FALSE, totalCount * sizeof(float), reinterpret_cast<void*>(m_offset)));
			m_offset += count * sizeof(float);
		}
	}

} }