#include "math/lyzm.h"

namespace lyz { namespace math {

	float to_radians(float angle)
	{
		return angle * M_PI / 180.0f;
	}

	float to_angle(float radian)
	{
		return radian * 180.0 / M_PI;
	}

	vec2 normalize(const vec2 & vec)
	{
		auto length = sqrtf(powf(vec.data[0], 2.0) + powf(vec.data[1], 2.0));
		return vec2(vec.data[0] / length, vec.data[1] / length);
	}
	
	vec3 normalize(const vec3 & vec)
	{
		auto length = sqrtf(
			powf(vec.data[0], 2.0) + 
			powf(vec.data[1], 2.0) + 
			powf(vec.data[2], 2.0)
		);
		return vec3(vec.data[0] / length, vec.data[1] / length, vec.data[2] / length);
	}
	
	vec4 normalize(const vec4 & vec)
	{
		auto length = sqrtf(
			powf(vec.data[0], 2.0) + 
			powf(vec.data[1], 2.0) + 
			powf(vec.data[2], 2.0) + 
			powf(vec.data[3], 2.0)
		);
		return vec4(vec.data[0] / length, vec.data[1] / length, vec.data[2] / length, vec.data[3] / length);
	}

	vec2 rotate(float x, float y, const vec2 & axis, float angle)
	{
		return vec2();
	}

	vec3 rotate(float x, float y, float z, const vec3 & axis, float angle)
	{
		vec4 result = (mat4::rotate(angle, axis)).mult(vec4(x, y, z, 1.0));
		return result.xyz();
	}

	vec3 rotate(const vec3 & vec, const vec3 & axis, float angle)
	{
		return rotate(vec.data[0], vec.data[1], vec.data[2], axis, angle);
	}

} }