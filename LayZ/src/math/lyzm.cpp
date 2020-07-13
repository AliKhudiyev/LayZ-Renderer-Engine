#include "math/lyzm.h"

namespace lyz { namespace math {

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

} }