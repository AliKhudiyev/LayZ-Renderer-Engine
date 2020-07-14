#include "math/vec4.h"

#include <assert.h>

namespace lyz { namespace math {

	vec4::vec4() {
		data[0] = data[1] = data[2] = data[3] = 0.0;
	}

	vec4::vec4(float x, float y, float z, float w)
	{
		data[0] = x;
		data[1] = y;
		data[2] = z;
		data[3] = w;
	}

	vec4::vec4(const float* fdata)
	{
		data[0] = fdata[0];
		data[1] = fdata[1];
		data[2] = fdata[2];
		data[3] = fdata[3];
	}

	vec4::vec4(const vec3& vec, float w)
	{
		data[0] = vec.data[0];
		data[1] = vec.data[1];
		data[2] = vec.data[2];
		data[3] = w;
	}

	vec4::vec4(const vec2& vect1, const vec2 & vect2)
	{
		data[0] = vect1.data[0];
		data[1] = vect1.data[1];
		data[2] = vect2.data[0];
		data[3] = vect2.data[1];
	}

	vec4::vec4(const vec4& vec)
	{
		data[0] = vec.data[0];
		data[1] = vec.data[1];
		data[2] = vec.data[2];
		data[3] = vec.data[3];
	}

	vec4::~vec4()
	{
	}

	vec3 vec4::xyz() const
	{
		return vec3(data[0], data[1], data[2]);
	}

	vec4 vec4::ones()
	{
		return vec4(1.0, 1.0, 1.0, 1.0);
	}

	vec4 vec4::to_vec4(const vec3 & vec, float w)
	{
		return vec4(vec.data[0], vec.data[1], vec.data[2], w);
	}

	float vec4::dist(const vec4& vec) const
	{
		return powf(pow(data[0] - vec.data[0], 2) +
			pow(data[1] - vec.data[1], 2) +
			pow(data[2] - vec.data[2], 2), 0.5);
	}

	float vec4::dot(const vec4& vec) const
	{
		return	
			data[0] * vec.data[0] + 
			data[1] * vec.data[1] + 
			data[2] * vec.data[2] + 
			data[3] * vec.data[3];
	}

	vec4 vec4::cross(const vec4& vec) const
	{
		// TODO: 
		vec3 u_vec {data[0], data[1], data[2]};
		vec3 tmp_vec {vec.data[0], vec.data[1], vec.data[2]};
		return vec4(u_vec.cross(tmp_vec), data[3]);
	}

	vec4 vec4::add(const vec4& vec) const
	{
		return vec4(data[0] + vec.data[0],
			data[1] + vec.data[1],
			data[2] + vec.data[2],
			1);
	}

	vec4 vec4::subtract(const vec4& vec) const
	{
		return vec4(data[0] - vec.data[0],
			data[1] - vec.data[1],
			data[2] - vec.data[2],
			1);
	}

	vec4 vec4::mult(const vec4& vec) const
	{
		return vec4(data[0] * vec.data[0],
			data[1] * vec.data[1],
			data[2] * vec.data[2],
			1);
	}

	vec4 vec4::mult(float val) const
	{
		return vec4(val * data[0], val * data[1], val * data[2], 1);
	}

	float& vec4::operator[](unsigned int i)
	{
		assert(i < 4);
		return data[i];
	}

	vec4 vec4::operator+(const vec4& vec) const
	{
		return add(vec);
	}

	vec4 vec4::operator-(const vec4& vec) const
	{
		return subtract(vec);
	}

	vec4& vec4::operator+=(const vec4& vec)
	{
		*this = *this + vec;
		return *this;
	}

	vec4& vec4::operator-=(const vec4& vec)
	{
		*this = *this - vec;
		return *this;
	}

	vec4& vec4::operator=(const vec4& vec)
	{
		data[0] = vec.data[0];
		data[1] = vec.data[1];
		data[2] = vec.data[2];
		data[3] = vec.data[3];

		return *this;
	}

	bool vec4::operator==(const vec4& vec) const
	{
		return (data[0] == vec.data[0] &&
			data[1] == vec.data[1] &&
			data[2] == vec.data[2] &&
			data[3] == vec.data[3]);
	}

	bool vec4::operator!=(const vec4& vec) const
	{
		return !(*this == vec);
	}
} }

std::ostream& operator<<(std::ostream& stream, const lyz::math::vec4& v) {
	stream << "(" << v.data[0] << ", " << v.data[1] << ", " << v.data[2] << ", " << v.data[3] << ")";
	return stream;
}