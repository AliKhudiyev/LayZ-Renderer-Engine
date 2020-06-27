#pragma once

#include "vec3.h"

#include <cmath>
#include <vector>
#include <iostream>

namespace lyz { namespace math {

	struct vec4 {
		union {
			float data[4];
			struct {
				vec3 u_vec;
				float u_w;
			};
			struct {
				float x, y, z, w;
			};
			struct {
				float r, g, b, a;
			};
		};

		vec4();
		vec4(float x, float y, float z, float w);
		vec4(const float* fdata);
		vec4(const vec3& vec, float w);
		vec4(const vec2& vect1, const vec2& vect2);
		vec4(const vec4& vec);
		~vec4();

		vec3 xyz() const;

		static vec4 ones();
		static vec4 to_vec4(const vec3& vec, float w = 1.0);

		float dist(const vec4& vec) const;
		float dot(const vec4& vec) const;
		vec4 cross(const vec4& vec) const;
		vec4 add(const vec4& vec) const;
		vec4 subtract(const vec4& vec) const;
		vec4 mult(const vec4& vec) const;
		vec4 mult(float val) const;

		float& operator[](unsigned int i);
		vec4 operator+(const vec4& vec) const;
		vec4 operator-(const vec4& vec) const;
		vec4& operator+=(const vec4& vec);
		vec4& operator-=(const vec4& vec);
		vec4& operator=(const vec4& vec);
		bool operator==(const vec4& vec) const;
		bool operator!=(const vec4& vec) const;
	};

} }

std::ostream& operator<<(std::ostream &stream, const lyz::math::vec4 &v);
