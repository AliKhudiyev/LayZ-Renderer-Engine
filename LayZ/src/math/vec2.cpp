#include "math/vec2.h"

#include <cassert>

namespace lyz { namespace math {
	vec2::vec2(float x, float y) {
		data[0] = x;
		data[1] = y;
	}

	vec2::vec2(const float* fdata) {
		data[0] = fdata[0];
		data[1] = fdata[1];
	}

	vec2::vec2(const vec2& vec) {
		data[0] = vec.data[0];
		data[1] = vec.data[1];
	}

	vec2::~vec2() {
		;
	}

	float vec2::dist(const vec2 & vec) const
	{
		return powf(powf(data[0] - vec.data[0], 2) + pow(data[1] - vec.data[1], 2), 0.5);
	}

	float vec2::dot(const vec2 & vec) const
	{
		return data[0] * vec.data[0] + data[1] * vec.data[1];
	}

	vec2 vec2::add(const vec2 & vec) const
	{
		return vec2(data[0] + vec.data[0], data[1] + vec.data[1]);
	}

	vec2 vec2::subtract(const vec2 & vec) const
	{
		return vec2(data[0] - vec.data[0], data[1] - vec.data[1]);
	}

	vec2 vec2::mult(const vec2& vec) const
	{
		return vec2(data[0] * vec.data[0], data[1] * vec.data[1]);
	}

	vec2 vec2::mult(float val) const
	{
		return vec2(val * data[0], val * data[1]);
	}

	float vec2::operator[](unsigned int i) const
	{
		assert(i < 2);
		return data[i];
	}

	vec2 vec2::operator+(const vec2 & vec) const
	{
		return vec2();
	}

	vec2 vec2::operator-(const vec2 & vec) const
	{
		return add(vec);
	}

	vec2& vec2::operator+=(const vec2 & vec)
	{
		*this = *this + vec;
		return *this;
	}

	vec2& vec2::operator-=(const vec2 & vec)
	{
		*this = *this - vec;
		return *this;
	}

	vec2& vec2::operator=(const vec2& vec) {
		data[0] = vec.data[0];
		data[1] = vec.data[1];

		return *this;
	}

	bool vec2::operator==(const vec2 & vec) const
	{
		return (data[0] == vec.data[0] && data[1] == vec.data[1]);
	}

	bool vec2::operator!=(const vec2 & vec) const
	{
		return !(*this == vec);
	}
} }

std::ostream &operator<<(std::ostream &stream, const lyz::math::vec2 &v) {
	stream << "(" << v[0] << ", " << v[1] << ")";
	return stream;
}