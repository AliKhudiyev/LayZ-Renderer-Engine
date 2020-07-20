#pragma once

#include "math/lyzm.h"
#include "utils/utils.h"

#include "graphics/renderer.h"
#include "graphics/instanceRenderer.h"
#include "graphics/pixelRenderer.h"

#define LYZ_NO_RENDERER nullptr

namespace lyz { namespace graphics {

	enum CameraType {
		ORTHOGRAPHIC = 0,
		PERSPECTIVE
	};

	class Camera {
	protected:
		math::vec3 
			m_position = math::vec3(0.0f, 0.0f, 0.0f), 
			m_target = math::vec3(0.0f, 0.0f, 0.0f), 
			m_up = math::vec3(0.0f, 1.0f, 0.0f)
		;

		float 
			m_left = -1.0f, m_right = 1.0f, 
			m_top = 1.0f, m_bottom = -1.0f, 
			m_near = 1.0f, m_far = 1.0f
		;

		math::mat4 m_model = math::mat4::identity();
		math::mat4 m_projection = math::mat4::identity();
		math::mat4 m_transformation;

		float 
			m_velocity = 1.0f, 
			m_accelaration = 0.0f, 
			m_deltatime = 1.0f,
			m_zoom = 1.0f
		;
		
		Renderer* m_renderer = nullptr;

	protected:
		Camera();

	public:
		virtual ~Camera();

		virtual void setViewSpace(float left, float right, float top, float bottom, float near, float far);
		virtual void setRenderer(Renderer* renderer);
		virtual void setVelocity(float velocity);
		virtual void setAccelration(float accelaration);
		virtual void setDeltaTime(float deltatime);
		virtual void setZoom(float zoom);
		virtual void setPosition(float x, float y, float z);
		virtual void setPosition(const math::vec3& position);
		virtual void setTarget(float x, float y, float z);
		virtual void setTarget(const math::vec3& target);
		virtual void setUp(float x, float y, float z);
		virtual void setUp(const math::vec3& up);
		virtual void rotate(float angle);
		virtual math::mat4 lookAt(const math::vec3& position, const math::vec3& target, const math::vec3& up, float zoom = -1.0);
		virtual math::mat4 lookAt(const math::vec3& position, const math::vec3& target, float angle = 0.0, float zoom = -1.0);
	
		inline virtual float getVelocity() const { return m_velocity; }
		inline virtual float getAccelaration() const { return m_accelaration; }
		inline virtual float getDeltaTime() const { return m_deltatime; }
		inline virtual const math::vec3& getPosition() const { return m_position; }
		inline virtual const math::vec3& getTarget() const { return m_target; }
		inline virtual const math::vec3& getUp() const { return m_up; }
		inline virtual const math::vec3 getDirection() const { return m_position - m_target; }
		inline virtual const math::vec3 getRight() const { return m_up.cross(getDirection()); }
		
	private:
		virtual void updateCamera() = 0;
	};

} }
