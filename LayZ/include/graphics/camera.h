#pragma once

#include "math/lyzm.h"
#include "utils/utils.h"

#include "graphics/renderer.h"
#include "graphics/instanceRenderer.h"
#include "graphics/pixelRenderer.h"

#define LYZ_NO_RENDERER nullptr

namespace lyz { namespace graphics {

	class Camera {
	private:
		math::vec3 
			m_position = math::vec3(0.0, 0.0, 0.0), 
			m_target = math::vec3(0.0, 0.0, 0.0), 
			m_up = math::vec3(0.0, 1.0, 0.0)
		;

		math::vec3 m_space[2] = {
			{ -1.0, 1.0, 1.0 },
			{ 1.0, -1.0, -1.0 }
		};
		// m_space[0] : left, top, near
		// m_space[1] : right, bottom, far

		float 
			m_velocity = 1.0f, 
			m_accelaration = 0.0f, 
			m_deltatime = 1.0
		;
		
		static Camera* camera;
		Renderer* m_renderer = nullptr;

	protected:
		Camera(Renderer* renderer);

	public:
		static Camera* getCamera(Renderer* renderer);
		static Camera* getCamera(RendererType type);
		~Camera();

		void setRenderer(Renderer* renderer);
		void setViewSpace(float left, float right, float top, float bottom, float near, float far);
		void setVelocity(float velocity);
		void setAccelration(float accelaration);
		void setDeltaTime(float deltatime);
		void setPosition(float x, float y, float z);
		void setPosition(const math::vec3& position);
		void setTarget(float x, float y, float z);
		void setTarget(const math::vec3& target);
		void setUp(float x, float y, float z);
		void setUp(const math::vec3& up);
		void rotate(float angle);
		void lookAt(const math::vec3& position, const math::vec3& target, const math::vec3& up);
		void lookAt(const math::vec3& position, const math::vec3& target, float angle = 0.0);
	
		inline float getVelocity() const { return m_velocity; }
		inline float getAccelaration() const { return m_accelaration; }
		inline float getDeltaTime() const { return m_deltatime; }
		inline const math::vec3& getPosition() const { return m_position; }
		inline const math::vec3& getTarget() const { return m_target; }
		inline const math::vec3& getUp() const { return m_up; }
		//inline const float getAngle() const { return 0.0; }
	};

} }
