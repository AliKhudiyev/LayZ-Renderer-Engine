#include "math/vec3.h"

#include <cassert>

namespace lyz { namespace math {

	vec3::vec3(float x, float y, float z) {
		data[0] = x;
		data[1] = y;
		data[2] = z;
	}

	vec3::vec3(const float* fdata) {
		data[0] = fdata[0];
		data[1] = fdata[1];
		data[2] = fdata[2];
	}

	vec3::vec3(const vec3& vec)
	{
		data[0] = vec.data[0];
		data[1] = vec.data[1];
		data[2] = vec.data[2];
	}

	vec3::vec3(const vec2& vec, float z)
	{
		data[0] = vec.data[0];
		data[1] = vec.data[1];
		data[2] = z;
	}

	vec3::~vec3()
	{
	}

	float vec3::dist(const vec3& vec) const
	{
		return powf(
			powf(data[0] - vec.data[0], 2) +
			powf(data[1] - vec.data[1], 2) +
			powf(data[2] - vec.data[2], 2), 0.5);
	}

	float vec3::dot(const vec3& vec) const
	{
		return data[0] * vec.data[0] + data[1] * vec.data[1] + data[2] * vec.data[2];
	}

	vec3 vec3::cross(const vec3& vec) const
	{
		return vec3(
			data[1] * vec.data[2] - data[2] * vec.data[1],
			data[2] * vec.data[0] - data[0] * vec.data[2],
			data[0] * vec.data[1] - data[1] * vec.data[0]
		);
	}

	vec3 vec3::add(const vec3& vec) const
	{
		return vec3(
			data[0] + vec.data[0],
			data[1] + vec.data[1],
			data[2] + vec.data[2]
		);
	}

	vec3 vec3::subtract(const vec3& vec) const
	{
		return vec3(
			data[0] - vec.data[0],
			data[1] - vec.data[1],
			data[2] - vec.data[2]
		);
	}

	vec3 vec3::mult(const vec3& vec) const
	{
		return vec3(
			data[0] * vec.data[0],
			data[1] * vec.data[1],
			data[2] * vec.data[2]
		);
	}

	vec3 vec3::mult(float val) const
	{
		return vec3(val * data[0], val * data[1], val * data[2]);
	}

	float vec3::operator[](unsigned int i) const
	{
		assert(i < 3);
		return data[i];
	}

	vec3 vec3::operator+(const vec3& vec) const
	{
		return add(vec);
	}

	vec3 vec3::operator-(const vec3& vec) const
	{
		return subtract(vec);
	}

	vec3& vec3::operator+=(const vec3& vec)
	{
		*this = *this + vec;
		return *this;
	}

	vec3& vec3::operator-=(const vec3& vec)
	{
		*this = *this - vec;
		return *this;
	}

	vec3& vec3::operator=(const vec3& vec)
	{
		data[0] = vec.data[0];
		data[1] = vec.data[1];
		data[2] = vec.data[2];

		return *this;
	}

	bool vec3::operator==(const vec3& vec) const
	{
		return (data[0] == vec.data[0] && data[1] == vec.data[1] && data[2] == vec.data[2]);
	}

	bool vec3::operator!=(const vec3& vec) const
	{
		return !(*this == vec);
	}
} }

std::ostream& operator<<(std::ostream& stream, const lyz::math::vec3 &v) {
	stream << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
	return stream;
}