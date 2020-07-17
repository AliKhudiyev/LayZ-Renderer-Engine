#include "graphics/texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "vendor/stb/stb_image.h"

namespace lyz { namespace graphics {

	Texture::Texture(const char* filepath):
		m_filepath(filepath)
	{
		LYZ_CALL(glGenTextures(1, &m_ID));

		LYZ_CALL(glBindTexture(GL_TEXTURE_2D, m_ID));
		// set the texture wrapping/filtering options (on the currently bound texture object)
		LYZ_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
		LYZ_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
		LYZ_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		LYZ_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		// load and generate the texture

		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char *data = stbi_load(filepath, &width, &height, &nrChannels, 0);
		
		m_width = width;
		m_height = height;

		if (!data) {
			std::cerr << "ERROR[texture loading]: Could not load the texture file!\n";
			assert(false);
		}

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		
		stbi_image_free(data);
	}
	
	Texture::~Texture()
	{
	}
	
	void Texture::enable() const
	{
		LYZ_CALL(glBindTexture(GL_TEXTURE_2D, m_ID));
	}
	
	void Texture::disable() const
	{
		LYZ_CALL(glBindTexture(GL_TEXTURE_2D, 0));
	}

} }