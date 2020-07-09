#pragma once

#include <vector>

#include "math/lyzm.h"

namespace lyz { namespace utils {

	std::vector<math::vec2> tell_texCoords(const std::vector<math::vec2>& vertices);
	std::vector<math::vec2> tell_texCoords(const std::vector<math::vec3>& vertices);

} }
