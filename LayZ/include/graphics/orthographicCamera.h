#pragma once

#include "graphics/camera.h"

namespace lyz { namespace graphics {

	class OrthographicCamera : public Camera {
	private:
		float m_left, m_right, m_top, m_bottom, m_near, m_far;

		static OrthographicCamera* camera;

	private:
		OrthographicCamera();

	public:
		static OrthographicCamera* getCamera();
		~OrthographicCamera();

		void setViewSpace(float left, float right, float top, float bottom, float near, float far);
	
	private:
		void updateCamera() override;
	};

} }
