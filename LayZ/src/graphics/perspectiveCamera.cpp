#include "graphics/perspectiveCamera.h"

namespace lyz { namespace graphics {

	PerspectiveCamera* PerspectiveCamera::camera = nullptr;

	PerspectiveCamera::PerspectiveCamera()
	{
	}

	PerspectiveCamera * PerspectiveCamera::getCamera()
	{
		if (!PerspectiveCamera::camera) {
			PerspectiveCamera::camera = new PerspectiveCamera();
		}
		return PerspectiveCamera::camera;
	}
	
	PerspectiveCamera::~PerspectiveCamera()
	{
		delete PerspectiveCamera::camera;
	}
	
	void PerspectiveCamera::setViewSpace(float left, float right, float top, float bottom, float near, float far)
	{
		std::cout << "Setting view space for the perspective camera...\n";

		m_left = left; m_right = right;
		m_top = top; m_bottom = bottom;
		m_near = near; m_far = far;

		updateCamera();
	}

	void PerspectiveCamera::setViewSpace(float fov, float aspectRatio, float near, float far)
	{
		m_fov = fov;
		m_aspectRatio = aspectRatio;
		m_near = near; m_far = far;

		updateCamera();
	}

	void PerspectiveCamera::updateCamera()
	{
		//std::cout << "Updating camera...\n";

		m_renderer->popTransformation();
		m_projection = math::mat4::perspective(m_left, m_right, m_bottom, m_top, m_near, m_far);
			// math::mat4::perspective(m_fov, m_aspectRatio, m_near, m_far);
		m_transformation = m_model * m_projection;
		//std::cout << m_model << "\n\n" << m_projection << "\n\n" << m_transformation.mult(math::vec4(1.0, -1.0, 0.0, 1.0)) << "\n\n";
		
		m_renderer->setTransformation(m_transformation);
	}

} }