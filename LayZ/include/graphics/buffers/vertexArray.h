#pragma once

#include "graphics/buffers/buffer.h"

namespace lyz { namespace graphics {

	class VertexArray : public Buffer {
	public:
		VertexArray();
		~VertexArray();

		void enable() const override;
		void disable() const override;
	};

} }
