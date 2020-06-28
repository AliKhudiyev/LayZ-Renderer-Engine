#pragma once

#include "graphics/buffers/buffer.h"

namespace lyz { namespace graphics {

	class IndexBuffer : public Buffer {
	public:
		IndexBuffer() = default;
		IndexBuffer(GLvoid* data, GLsizei size);
		~IndexBuffer();

		void enable() const override;
		void disable() const override;

		void setData(GLvoid* data, GLsizei size) override;
	};

} }
