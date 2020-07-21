#include "utils/processing.h"

#include <algorithm>

namespace lyz { namespace utils {

	std::vector<math::vec2> tell_texCoords(const std::vector<math::vec2>& vertices)
	{
		std::vector<math::vec2> texCoords;
		std::vector<float> x_coords, y_coords;
		
		for (const auto& vertex : vertices) {
			x_coords.push_back(vertex.data[0]);
			y_coords.push_back(vertex.data[1]);
		}

		float x_min = *std::min_element(x_coords.cbegin(), x_coords.cend());
		float x_max = *std::max_element(x_coords.cbegin(), x_coords.cend());
		float y_min = *std::min_element(y_coords.cbegin(), y_coords.cend());
		float y_max = *std::max_element(y_coords.cbegin(), y_coords.cend());

		// f: x -> X (f(x) = a_f * x + b_f) where x is a vertex coord and X is a texture coord
		// g: y -> Y (g(y) = a_g * x + b_g) where y is a vertex coord and Y is a texture coord

		float a_f = 1.0 / (x_max - x_min), b_f = -x_min * a_f;
		float a_g = 1.0 / (y_max - y_min), b_g = -y_min * a_g;

		for (const auto vertex : vertices) {
			auto texCoord = math::vec2(a_f * vertex.data[0] + b_f, a_g * vertex.data[1] + b_g);
			texCoords.push_back(texCoord);
		}

		return texCoords;
	}

	std::vector<math::vec2> tell_texCoords(const std::vector<math::vec3>& vertices)
	{
		std::vector<math::vec2> verts;

		for (const auto& vertex : vertices) {
			verts.push_back(math::vec2(vertex.data[0], vertex.data[1]));
		}

		return tell_texCoords(verts);
	}

} }