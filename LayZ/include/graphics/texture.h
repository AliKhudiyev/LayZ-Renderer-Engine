#pragma once

namespace lyz { namespace graphics {

	class Texture {
	private:
		unsigned m_ID;

	public:
		Texture();
		~Texture();

		void enable() const;
		void disable() const;
	};

} }
