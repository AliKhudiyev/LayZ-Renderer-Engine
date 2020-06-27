#include "graphics/buffers/indexBuffer.h"

namespace lyz { namespace graphics {

	IndexBuffer::IndexBuffer(GLvoid * data, GLsizei size)
	{
		LYZ_CALL(glGenBuffers(1, &m_ID));
		LYZ_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID));
		LYZ_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	}
	
	IndexBuffer::~IndexBuffer()
	{
	}
	
	void IndexBuffer::enable() const
	{
		LYZ_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID));
	}
	
	void IndexBuffer::disable() const
	{
		LYZ_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

} }