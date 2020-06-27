#pragma once

#include "graphics/buffers/buffer.h"

#include <initializer_list>

namespace lyz { namespace graphics {

	class VertexBuffer : public Buffer {
	private:
		unsigned m_indexSlot = 0;
		unsigned m_offset = 0;

	public:
		VertexBuffer(GLvoid* data, GLsizei size);
		~VertexBuffer();

		void enable() const;
		void disable() const;

		void setLayout(const std::initializer_list<unsigned>& batchCounts);
	};

} }
