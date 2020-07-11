#include "graphics/camera.h"

namespace lyz { namespace graphics {
	
	Camera* Camera::camera = nullptr;

	Camera::Camera(float left, float right, float top, float bottom, float near, float far)
	{
		m_space[0] = math::vec3(left, top, near);
		m_space[1] = math::vec3(right, bottom, far);
	}
	
	Camera * Camera::getCamera(float left, float right, float top, float bottom, float near, float far)
	{
		if (!Camera::camera) {
			Camera::camera = new Camera(left, right, top, bottom, near, far);
		}
		return Camera::camera;
	}

	Camera::~Camera()
	{
	}
	
	void Camera::setVelocity(float velocity)
	{
		m_velocity = velocity;
	}
	
	void Camera::setAccelration(float accelaration)
	{
		m_accelaration = accelaration;
	}

	void Camera::setDeltaTime(float deltatime)
	{
		m_deltatime = deltatime;
	}
	
	void Camera::setPosition(float x, float y, float z)
	{
		m_position.data[0] = x;
		m_position.data[1] = y;
		m_position.data[2] = z;
	}
	
	void Camera::setPosition(const math::vec3 & position)
	{
		m_position = position;
	}
	
	void Camera::setTarget(float x, float y, float z)
	{
		m_target.data[0] = x;
		m_target.data[1] = y;
		m_target.data[2] = z;
	}
	
	void Camera::setTarget(const math::vec3 & target)
	{
		m_target = target;
	}
	
	void Camera::setUp(float x, float y, float z)
	{
		m_up.data[0] = x;
		m_up.data[1] = y;
		m_up.data[2] = z;
	}
	
	void Camera::setUp(const math::vec3 & up)
	{
		m_up = up;
	}
	
	void Camera::rotate(float angle)
	{
	}
	
	void Camera::lookAt(const math::vec3 & position, const math::vec3 & target, const math::vec3 & up)
	{
	}
	
	void Camera::lookAt(const math::vec3 & position, const math::vec3 & target, float angle)
	{
	}

} }