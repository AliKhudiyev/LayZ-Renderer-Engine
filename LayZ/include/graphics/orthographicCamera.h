#pragma once

#include "graphics/camera.h"

namespace lyz { namespace graphics {

	class OrthographicCamera : public Camera {
	private:
		static OrthographicCamera* camera;

	private:
		OrthographicCamera();

	public:
		static OrthographicCamera* getCamera();
		~OrthographicCamera();

		void setViewSpace(float left, float right, float top, float bottom, float near, float far) override;
	
	private:
		void updateCamera() override;
	};

} }
