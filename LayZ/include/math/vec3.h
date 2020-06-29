#pragma once

#include "vec2.h"

namespace lyz { namespace math {

	struct vec3 {
		float data[3];

		vec3() = default;
		vec3(float x, float y, float z);
		vec3(const float* fdata);
		vec3(const vec3& vec);
		vec3(const vec2& vec, float z = 0);
		~vec3();

		float dist(const vec3& vec) const;
		float dot(const vec3& vec) const;
		vec3 cross(const vec3& vec) const;
		vec3 add(const vec3& vec) const;
		vec3 subtract(const vec3& vec) const;
		vec3 mult(const vec3& vec) const;
		vec3 mult(float val) const;

		float operator[](unsigned int i) const;
		vec3 operator+(const vec3& vec) const;
		vec3 operator-(const vec3& vec) const;
		vec3& operator+=(const vec3& vec);
		vec3& operator-=(const vec3& vec);
		vec3& operator=(const vec3& vec);
		bool operator==(const vec3& vec) const;
		bool operator!=(const vec3& vec) const;
	};
} }

std::ostream& operator<<(std::ostream &stream, const lyz::math::vec3 &v);
