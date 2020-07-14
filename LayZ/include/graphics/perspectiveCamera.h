#pragma once

#include "graphics/camera.h"

namespace lyz { namespace graphics {

	class PerspectiveCamera : public Camera {
	private:
		float m_fov, m_aspectRatio, m_near, m_far;

		static PerspectiveCamera* camera;

	private:
		PerspectiveCamera();

	public:
		static PerspectiveCamera* getCamera();
		~PerspectiveCamera();

		void setViewSpace(float fov, float aspectRatio, float near, float far);
	
	private:
		void updateCamera() override;
	};

} }
