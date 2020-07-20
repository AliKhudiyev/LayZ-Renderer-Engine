#pragma once

#include "vec4.h"

#include <cmath>
#include <vector>
#include <iostream>

namespace lyz { namespace math {

	struct mat4 {
		union {
			float data[16];
			vec4 vecs[4];
		};

		mat4();
		mat4(const vec4& vect1, const vec4& vect2, const vec4& vect3, const vec4& vect4);
		mat4(const vec4* vdata);
		mat4(const float* fdata);
		mat4(const mat4& mat);
		~mat4();

		static mat4 ones();
		static mat4 identity(float val = 1.0);
		static mat4 translate(float x, float y, float z);
		static mat4 scale(float x, float y, float z);
		static mat4 rotate(float angle, const vec3& axis);
		static mat4 rotate(float angle, const vec3& begin, const vec3& end);
		static mat4 ortho(float left, float right, float bottom, float top, float near, float far);
		static mat4 perspective(float left, float right, float bottom, float top, float near, float far);
		static mat4 perspective(float fov, float aspect_ratio, float near, float far);
		static mat4 transpose(const mat4& mat);

		const mat4 add(const mat4& mat) const;
		const mat4 subtract(const mat4& mat) const;
		const mat4 mat_mult(const mat4& mat) const;
		const mat4 mat_mult(float val) const;
		const mat4 mult(const mat4& mat) const;
		const vec4 mult(const vec4& vec) const;

		vec4 operator[](unsigned int i) const;
		mat4& operator=(const mat4& mat);
		const mat4 operator+(const mat4& mat) const;
		const mat4 operator-(const mat4& mat) const;
		const mat4 operator*(const mat4& mat) const;
		const vec4 operator*(const vec4& vec) const;
		const mat4 operator*(float val) const;
		mat4& operator+=(const mat4& mat);
		mat4& operator-=(const mat4& mat);
		mat4& operator*=(const mat4& mat);
		mat4& operator*=(float val);
		bool operator==(const mat4& mat) const;
		bool operator!=(const mat4& mat) const;
	};
} }

std::ostream& operator<<(std::ostream& stream, const lyz::math::mat4& v);
