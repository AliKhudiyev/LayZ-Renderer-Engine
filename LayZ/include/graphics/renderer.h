#pragma once

#include "graphics/buffers/buffers.h"

#include "graphics/renderable.h"
#include "graphics/shader.h"

#define LYZ_RENDERER_STORE_START		true
#define LYZ_RENDERER_STORE_STOP			false

#define LYZ_VERTEX_COORD_ELEMENTS		3
#define LYZ_VERTEX_COLOR_ELEMENTS		4
#define LYZ_VERTEX_TEXTURE_ELEMENTS		2
#define LYZ_VERTEX_SLOT_ELEMENTS		1
#define LYZ_VERTEXDATA_SIZE				(sizeof(coord_t) + sizeof(color_t) + sizeof(texture_t) + sizeof(slot_t))

// FACES are triangles
#define LYZ_RENDERER_MAX_FACES			2000000
#define LYZ_RENDERER_MAX_VERTICES		3 * LYZ_RENDERER_MAX_FACES
#define LYZ_RENDERER_MAX_INDICES		3 * LYZ_RENDERER_MAX_FACES
#define LYZ_RENDERER_MAX_VERTICES_SIZE	LYZ_VERTEXDATA_SIZE * LYZ_RENDERER_MAX_VERTICES

#define LYZ_RENDERER_MAX_LINES			10000
#define LYZ_RENDERER_MAX_POINTS			20000

#define LYZ_RENDERER_MAX_SHADERS		6

#define LYZ_DEFAULT_SHADER_PATH			"src/shaders/"

namespace lyz { namespace graphics {
	
	using renderer_status_t = bool;

	enum RendererType {
		Renderer_ = 0,
		Batch_Renderer = 0,
		Instance_Renderer,
		Pixel_Renderer
	};

	struct VertexData {
		coord_t coord;
		color_t color;
		texture_t texCoord;
		slot_t texSlot;
	};

	struct VertexDataLine {
		coord_t coord;
	};

	struct VertexDataPoint {
		coord_t coord;
	};

	class Renderer {
	private:
		VertexArray* m_vertexArray;
		VertexBuffer* m_vertexBuffer;
		IndexBuffer* m_indexBuffer, *m_indexBufferLine, *m_indexBufferPoint;

		VertexData* m_vertexData;

		renderer_status_t m_rendererStatus = LYZ_RENDERER_STORE_STOP;

		unsigned* m_indices = nullptr, *m_indicesLine = nullptr, *m_indicesPoint = nullptr;
		unsigned m_vertexCount = 0;
		unsigned m_indexCount = 0, m_indexCountLine = 0, m_indexCountPoint = 0;

		std::vector<math::mat4> m_transformations;

	protected:
		static Renderer* renderer;
		static Shader* shader;

		std::vector<unsigned> m_texIDs;

	protected:
		Renderer();

	public:
		~Renderer();

		static Renderer* getRenderer();

		virtual void loadShader(const char* vertexpath, const char* fragmentpath);
		virtual void loadShader(const char* shaderpath, ShaderType type);
		virtual void addTransformation(const math::mat4& transformation);
		virtual void setTransformation(const math::mat4& transformation);
		virtual math::mat4 popTransformation();
		virtual void store(const Renderable* renderable);
		virtual void draw();
		virtual void clear();
		
	protected:
		virtual void setStoreStatus(renderer_status_t status);

	private:
		void init();
	};

} }
