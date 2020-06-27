#pragma once

#include <iostream>
#include <cmath>

namespace lyz { namespace math {

	struct vec2 {
		union {
			float data[2];
			struct {
				float x, y;
			};
		};

		vec2() = default;
		vec2(float x, float y);
		vec2(const float* vec);
		vec2(const vec2& vec);
		~vec2();

		float dist(const vec2& vec) const;
		float dot(const vec2& vec) const;
		vec2 add(const vec2& vec) const;
		vec2 subtract(const vec2& vec) const;
		vec2 mult(const vec2& vec) const;
		vec2 mult(float val) const;

		float operator[](unsigned int i) const;
		vec2 operator+(const vec2& vec) const;
		vec2 operator-(const vec2& vec) const;
		vec2& operator+=(const vec2& vec);
		vec2& operator-=(const vec2& vec);
		vec2& operator=(const vec2& vec);
		bool operator==(const vec2& vec) const;
		bool operator!=(const vec2& vec) const;
	};
} }

std::ostream& operator<<(std::ostream &stream, const lyz::math::vec2 &v);
