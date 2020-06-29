#include "math/mat4.h"

#include <cmath>
#include <assert.h>

namespace lyz { namespace math {

	mat4::mat4() {
		for (unsigned int i = 0; i < 4; ++i) vecs[i] = vec4();
	}

	mat4::mat4(const vec4& vect1, const vec4& vect2, const vec4& vect3, const vec4& vect4)
	{
		vecs[0] = vect1;
		vecs[1] = vect2;
		vecs[2] = vect3;
		vecs[3] = vect4;
	}

	mat4::mat4(const vec4* vdata)
	{
		for (unsigned int i = 0; i < 4; ++i) vecs[i] = vdata[i];
	}

	mat4::mat4(const float* fdata)
	{
		for (unsigned int i = 0; i < 16; ++i) data[i] = fdata[i];
	}

	mat4::mat4(const mat4& mat)
	{
		for (unsigned int i = 0; i < 4; ++i) vecs[i] = mat.vecs[i];
	}

	mat4::~mat4()
	{
	}

	mat4 mat4::ones()
	{
		return mat4(vec4::ones(), vec4::ones(), vec4::ones(), vec4::ones());
	}

	mat4 mat4::identity(float val)
	{
		return mat4(
			vec4(val, 0.0, 0.0, 0.0),
			vec4(0.0, val, 0.0, 0.0),
			vec4(0.0, 0.0, val, 0.0),
			vec4(0.0, 0.0, 0.0, val)
		);
	}

	mat4 mat4::translate(float x, float y, float z)
	{
		return mat4(
			vec4(1.0, 0.0, 0.0, x),
			vec4(0.0, 1.0, 0.0, y),
			vec4(0.0, 0.0, 1.0, z),
			vec4(0.0, 0.0, 0.0, 1.0)
		);
	}

	mat4 mat4::scale(float x, float y, float z)
	{
		return mat4(
			vec4(x, 0.0, 0.0, 0.0),
			vec4(0.0, y, 0.0, 0.0),
			vec4(0.0, 0.0, z, 0.0),
			vec4(0.0, 0.0, 0.0, 1.0)
		);
	}

	mat4 mat4::rotate(float angle, const vec3& axis)
	{
		// TODO: 
		float rad = M_PI * angle / 180.0;
		float len = sqrtf(powf(axis.data[0], 2) + powf(axis.data[1], 2) + powf(axis.data[2], 2));
		const vec3 naxis(axis.data[0] / len, axis.data[1] / len, axis.data[2] / len);
		return mat4(
			vec4(cosf(rad)+powf(naxis.data[0], 2)*(1-cosf(rad)), naxis.data[0]*naxis.data[1]*(1-cosf(rad))-naxis.data[2]*sinf(rad), naxis.data[0]*naxis.data[2]*(1-cosf(rad))+naxis.data[1]*sinf(rad), 0.0),
			vec4(naxis.data[1]*naxis.data[0]*(1-cosf(rad))+naxis.data[2]*sinf(rad), cosf(rad)+powf(naxis.data[1], 2)*(1-cosf(rad)), naxis.data[1]*naxis.data[2]*(1-cosf(rad))-naxis.data[0]*sinf(rad), 0.0),
			vec4(naxis.data[2]*naxis.data[0]*(1-cosf(rad))-naxis.data[1]*sinf(rad), naxis.data[2]*naxis.data[1]*(1-cosf(rad))+naxis.data[0]*sinf(rad), cosf(rad)+powf(naxis.data[2], 2)*(1-cosf(rad)), 0.0),
			vec4(0.0, 0.0, 0.0, 1.0)
		);
	}

	mat4 mat4::rotate(float angle, const vec3 & begin, const vec3 & end)
	{
		const vec3 axis(end.data[0] - begin.data[0], end.data[2] - begin.data[2], end.data[2] - begin.data[2]);
		const mat4 rotation = mat4::rotate(angle, axis);
		mat4 result = mat4::translate(begin.data[0], begin.data[1], begin.data[2]) * rotation;

		return result;
	}

	mat4 mat4::ortho(float left, float right, float bottom, float top, float near, float far)
	{
		return mat4(
			vec4((float)(2.0 / (right - left)), 0.0, 0.0, (float)((left + right) / (left - right))),
			vec4(0.0, (float)(2.0 / (top - bottom)), 0.0, (float)((bottom + top) / (bottom - top))),
			vec4(0.0, 0.0, (float)(2.0 / (far - near)), (float)((near + far) / (near - far))),
			vec4(0.0, 0.0, 0.0, 1.0)
		);
	}

	mat4 mat4::perspective(float fov, float aspect_ratio, float, float)
	{
		// TODO: 
		return mat4();
	}

	const mat4 mat4::add(const mat4& mat) const
	{
		return mat4(vecs[0] + vecs[0],
			vecs[1] + vecs[1],
			vecs[2] + vecs[2],
			vecs[3] + vecs[3]);
	}

	const mat4 mat4::subtract(const mat4& mat) const
	{
		return mat4(vecs[0] - vecs[0],
			vecs[1] - vecs[1],
			vecs[2] - vecs[2],
			vecs[3] - vecs[3]);
	}

	const mat4 mat4::mat_mult(const mat4& mat) const
	{
		auto curr = *this;
		mat4 result;

		for (unsigned int row = 0; row < 4; ++row) {
			for (unsigned int col = 0; col < 4; ++col) {
				for (unsigned int i = 0; i < 4; ++i) {
					result.vecs[row][col] += curr[row][i] * mat[i][col];
				}
			}
		}
		return result;
	}

	const mat4 mat4::mat_mult(float val) const
	{
		return mat4(vecs[0].mult(val), vecs[1].mult(val), vecs[2].mult(val), vecs[3].mult(val));
	}

	const mat4 mat4::mult(const mat4& mat) const
	{
		return mat4(vecs[0].mult(mat[0]),
			vecs[1].mult(mat[1]),
			vecs[2].mult(mat[2]),
			vecs[3].mult(mat[3]));
	}

	vec4 mat4::operator[](unsigned int i) const
	{
		assert(i < 4);
		return vecs[i];
	}

	mat4& mat4::operator=(const mat4& mat)
	{
		for (unsigned int i = 0; i < 4; ++i) vecs[i] = mat.vecs[i];
		return *this;
	}

	const mat4 mat4::operator+(const mat4& mat) const
	{
		return add(mat);
	}

	const mat4 mat4::operator-(const mat4& mat) const
	{
		return subtract(mat);
	}

	const mat4 mat4::operator*(const mat4& mat) const
	{
		return mat_mult(mat);
	}

	const vec4 mat4::operator*(const vec4 & vec) const
	{
		vec4 result;
		for (unsigned i = 0; i < 4; ++i) {
			float ans = 0.f;
			for (unsigned j = 0; j < 4; ++j) {
				ans += vecs[i].data[j] * vec.data[j];
			}
			result.data[i] = ans;
		}
		return result;
	}

	const mat4 mat4::operator*(float val) const
	{
		return mat_mult(val);
	}

	mat4& mat4::operator+=(const mat4& mat)
	{
		*this = *this + mat;
		return *this;
	}

	mat4& mat4::operator-=(const mat4& mat)
	{
		*this = *this - mat;
		return *this;
	}

	mat4& mat4::operator*=(const mat4& mat)
	{
		*this = *this * mat;
		return *this;
	}

	mat4& mat4::operator*=(float val)
	{
		*this = *this * val;
		return *this;
	}

	bool mat4::operator==(const mat4& mat) const
	{
		return (vecs[0] == mat.vecs[0] &&
			vecs[1] == mat.vecs[1] &&
			vecs[2] == mat.vecs[2] &&
			vecs[3] == mat.vecs[3]);
	}

	bool mat4::operator!=(const mat4& mat) const
	{
		return !(*this == mat);
	}
} }

std::ostream& operator<<(std::ostream& stream, const lyz::math::mat4& m) {
	for (uint8_t row = 0; row < 4; ++row) {
		for (uint8_t col = 0; col < 4; ++col) {
			stream << m[row][col] << " ";
		}
		stream << std::endl;
	}
	return stream;
}