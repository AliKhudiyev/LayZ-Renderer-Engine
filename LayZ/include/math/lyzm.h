#pragma once

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

namespace lyz { namespace math {

	vec2 normalize(const vec2& vec);
	vec3 normalize(const vec3& vec);
	vec4 normalize(const vec4& vec);

	vec2 rotate(float x, float y, const vec2& axis, float angle);
	vec3 rotate(float x, float y, float z, const vec3& axis, float angle);
	vec3 rotate(const vec3& vec, const vec3& axis, float angle);

} }
