#pragma once

#include <string>

namespace lyz { namespace utils {

	class FileParser {
	public:
		FileParser();
		~FileParser();
	
		static std::string read(const std::string& filepath);
	};

} }
