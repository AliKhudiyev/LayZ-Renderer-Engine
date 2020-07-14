#include "graphics/camera.h"

namespace lyz { namespace graphics {
	
	Camera* Camera::camera = nullptr;

	Camera::Camera(Renderer* renderer)
	{
		if (renderer) {
			m_renderer = renderer;
		}
		else {
			m_renderer = Renderer::getRenderer();
			std::cout << "WARNING: Camera has been initialized with a default renderer!\n";
		}
	}
	
	Camera * Camera::getCamera(Renderer* renderer)
	{
		if (!Camera::camera) {
			Camera::camera = new Camera(renderer);
		}
		return Camera::camera;
	}

	Camera * Camera::getCamera(RendererType type)
	{
		if (!Camera::camera) {
			Renderer* renderer = nullptr;
			switch (type)
			{
			case lyz::graphics::Batch_Renderer:
				renderer = Renderer::getRenderer();
				break;
			case lyz::graphics::Instance_Renderer:
				renderer = InstanceRenderer::getRenderer();
				break;
			case lyz::graphics::Pixel_Renderer:
				renderer = PixelRenderer::getRenderer(640, 480);
				break;
			default:
				break;
			}
			Camera::camera = new Camera(renderer);
		}
		return Camera::camera;
	}

	Camera::~Camera()
	{
	}
	
	void Camera::setRenderer(Renderer * renderer)
	{
		m_renderer = renderer;
	}

	void Camera::setViewSpace(float left, float right, float top, float bottom, float near, float far)
	{
		m_space[0] = math::vec3(left, top, near);
		m_space[1] = math::vec3(right, bottom, far);
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
		m_position = position;
		m_target = target;
		m_up = math::normalize(up);

		// TO DO
		auto direction = math::normalize(m_position - m_target);
		auto right = math::normalize(m_up.cross(direction));
		m_up = math::normalize(direction.cross(right));

		auto transformation =
			math::mat4(
				math::vec4(right.data[0],		right.data[1],		right.data[2],		0.0),
				math::vec4(m_up.data[0],		m_up.data[1],		m_up.data[2],		0.0),
				math::vec4(direction.data[0],	direction.data[1],	direction.data[2],	0.0),
				math::vec4(0.0,					0.0,				0.0,				1.0)
			) * 
			math::mat4::translate(-position.data[0], -position.data[1], -position.data[2]);
		m_renderer->popTransformation();
		m_renderer->setTransformation(transformation);
	}
	
	void Camera::lookAt(const math::vec3 & position, const math::vec3 & target, float angle)
	{
		auto up = math::mat4::rotate(angle, m_position).mult(math::vec4(m_up, 1.0));
		lookAt(position, target, up.xyz());
	}

} }