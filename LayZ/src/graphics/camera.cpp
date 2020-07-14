#include "graphics/camera.h"

namespace lyz { namespace graphics {
	
	Camera::Camera()
	{
		m_renderer = Renderer::getRenderer();
	}

	Camera::~Camera()
	{
	}
	
	void Camera::setRenderer(Renderer * renderer)
	{
		if (renderer) {
			m_renderer = renderer;
		}
		else {
			std::cerr << "WARNING[setting camera renderer]: Trying to set null renderer!\n";
		}
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

	void Camera::setZoom(float zoom)
	{
		m_zoom = zoom;
	}
	
	void Camera::setPosition(float x, float y, float z)
	{
		m_position.data[0] = x;
		m_position.data[1] = y;
		m_position.data[2] = z;

		lookAt(m_position, m_target, m_up);
	}
	
	void Camera::setPosition(const math::vec3 & position)
	{
		m_position = position;

		lookAt(m_position, m_target, m_up);
	}
	
	void Camera::setTarget(float x, float y, float z)
	{
		m_target.data[0] = x;
		m_target.data[1] = y;
		m_target.data[2] = z;

		lookAt(m_position, m_target, m_up);
	}
	
	void Camera::setTarget(const math::vec3 & target)
	{
		m_target = target;

		lookAt(m_position, m_target, m_up);
	}
	
	void Camera::setUp(float x, float y, float z)
	{
		m_up.data[0] = x;
		m_up.data[1] = y;
		m_up.data[2] = z;

		lookAt(m_position, m_target, m_up);
	}
	
	void Camera::setUp(const math::vec3 & up)
	{
		m_up = up;

		lookAt(m_position, m_target, m_up);
	}
	
	void Camera::rotate(float angle)
	{
		// TO DO
	}
	
	void Camera::lookAt(const math::vec3 & position, const math::vec3 & target, const math::vec3 & up, float zoom)
	{
		m_position = position;
		m_target = target;
		m_up = math::normalize(up);

		if (zoom >= 0.0f) {
			if (zoom == 0.0f) {
				std::cerr << "WARNING[setting camera zoom]: Zoom level is 0.0!\n";
			}
			m_zoom = zoom;
		}

		auto direction = math::normalize(m_position - m_target);
		auto right = math::normalize(m_up.cross(direction));
		m_up = math::normalize(direction.cross(right));

		m_transformation =
			math::mat4(
				math::vec4(right.data[0],		right.data[1],		right.data[2],		0.0),
				math::vec4(m_up.data[0],		m_up.data[1],		m_up.data[2],		0.0),
				math::vec4(direction.data[0],	direction.data[1],	direction.data[2],	0.0),
				math::vec4(0.0,					0.0,				0.0,				1.0)
			) * 
			math::mat4::translate(-position.data[0], -position.data[1], -position.data[2]) *
			math::mat4::scale(m_zoom, m_zoom, m_zoom);
		
		m_renderer->popTransformation();
		m_renderer->setTransformation(m_transformation);
	}
	
	void Camera::lookAt(const math::vec3 & position, const math::vec3 & target, float angle, float zoom)
	{
		auto up = math::mat4::rotate(angle, m_position).mult(math::vec4(m_up, 1.0));
		lookAt(position, target, up.xyz(), zoom);
	}

} }