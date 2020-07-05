#pragma once

#include <vector>
#include <string>

namespace lyz { namespace utils {

	class FileParser {
	public:
		FileParser();
		~FileParser();

		static std::string read(const std::string& filepath);
		static std::vector<std::string> mread(const std::string& filepath);
	
	public:
		static const char fileTypeBegin;
		static const char fileTypeEnd;
	};

} }
