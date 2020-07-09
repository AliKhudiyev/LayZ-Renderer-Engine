#pragma once

#include "utils/utils.h"

namespace lyz { namespace graphics {

	class Texture {
	private:
		unsigned m_ID;
		size_t m_width, m_height;
		const char* m_filepath;

	public:
		Texture(const char* filepath);
		~Texture();

		void enable() const;
		void disable() const;

		inline unsigned getID() const { return m_ID; }
		inline size_t getWidth() const { return m_width; }
		inline size_t getHeight() const { return m_height; }
	};

} }
