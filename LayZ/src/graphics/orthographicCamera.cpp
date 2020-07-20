#include "graphics/orthographicCamera.h"

namespace lyz { namespace graphics {

	OrthographicCamera* OrthographicCamera::camera = nullptr;

	OrthographicCamera::OrthographicCamera()
	{
	}

	OrthographicCamera * OrthographicCamera::getCamera()
	{
		if (!OrthographicCamera::camera) {
			OrthographicCamera::camera = new OrthographicCamera();
		}
		return OrthographicCamera::camera;
	}
	
	OrthographicCamera::~OrthographicCamera()
	{
		delete OrthographicCamera::camera;
	}
	
	void OrthographicCamera::setViewSpace(float left, float right, float top, float bottom, float near, float far)
	{
		m_left = left; m_right = right;
		m_top = top; m_bottom = bottom;
		m_near = near; m_far = far;

		updateCamera();
	}

	void OrthographicCamera::updateCamera()
	{
		m_renderer->popTransformation();
		m_projection = math::mat4::ortho(m_left, m_right, m_bottom, m_top, m_near, m_far);
		m_transformation = m_model * m_projection;
		std::cout << m_transformation << "\n\n";
		m_renderer->setTransformation(m_transformation);
	}

} }