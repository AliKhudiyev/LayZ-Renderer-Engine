#pragma once

#include "graphics/buffers/buffers.h"

#include "graphics/renderable.h"
#include "graphics/shader.h"

#define LYZ_RENDERER_STORE_START		true
#define LYZ_RENDERER_STORE_STOP			false

#define LYZ_VERTEX_COORD_ELEMENTS		3
#define LYZ_VERTEX_COLOR_ELEMENTS		4
#define LYZ_VERTEXDATA_SIZE				(sizeof(coord_t) + sizeof(color_t))

// FACES are triangles
#define LYZ_RENDERER_MAX_FACES			2000000
#define LYZ_RENDERER_MAX_VERTICES		3 * LYZ_RENDERER_MAX_FACES
#define LYZ_RENDERER_MAX_INDICES		3 * LYZ_RENDERER_MAX_FACES
#define LYZ_RENDERER_MAX_VERTICES_SIZE	LYZ_VERTEXDATA_SIZE * LYZ_RENDERER_MAX_VERTICES

#define LYZ_RENDERER_MAX_SHADERS		6

#define LYZ_DEFAULT_SHADER_PATH			"src/shaders/"

namespace lyz { namespace graphics {
	
	using renderer_status_t = bool;

	struct VertexData {
		coord_t coord;
		color_t color;
	};

	class Renderer {
	private:
		VertexArray* m_vertexArray;
		VertexBuffer* m_vertexBuffer;
		IndexBuffer* m_indexBuffer;

		VertexData* m_vertexData;

		renderer_status_t m_rendererStatus = LYZ_RENDERER_STORE_STOP;

		unsigned* m_indices = nullptr;
		unsigned m_vertexCount = 0;
		unsigned m_indexCount = 0;

	protected:
		static Renderer* renderer;
		static Shader* shader;

	protected:
		Renderer();

	public:
		~Renderer();

		static Renderer* getRenderer();

		virtual void loadShader(const char* vertexpath, const char* fragmentpath);
		virtual void loadShader(const char* shaderpath, ShaderType type);
		virtual void store(const Renderable* renderable);
		virtual void draw();
		virtual void clear();
		
	protected:
		virtual void setStoreStatus(renderer_status_t status);

	private:
		void init();
	};

} }
