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
	
	void PerspectiveCamera::setViewSpace(float fov, float aspectRatio, float near, float far)
	{
		m_fov = fov;
		m_aspectRatio = aspectRatio;
		m_near = near; m_far = far;

		updateCamera();
	}

	void PerspectiveCamera::updateCamera()
	{
		m_transformation = math::mat4::perspective(m_fov, m_aspectRatio, m_near, m_far);
	}

} }