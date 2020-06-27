#include "graphics/buffers/vertexArray.h"

namespace lyz { namespace graphics {

	VertexArray::VertexArray()
	{
		LYZ_CALL(glGenVertexArrays(1, &m_ID));
		LYZ_CALL(glBindVertexArray(m_ID));
	}
	
	VertexArray::~VertexArray()
	{
	}

	void VertexArray::enable() const
	{
		LYZ_CALL(glBindVertexArray(m_ID));
	}

	void VertexArray::disable() const
	{
		LYZ_CALL(glBindVertexArray(0));
	}

} }