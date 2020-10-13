#pragma once

#include <vector>
#include <string>

namespace lyz { namespace shaders {

    enum OSType {
        Linux = 0,
        MacOS,
        Windows32,
        Windows64,
        Other
    };

//    std::string vertex_shader;
//    std::string tessellationControl_shader;
//    std::string tessellationEvaluation_shader;
//    std::string geometry_shader;
//    std::string fragment_shader;
//    std::string compute_shader;

} }

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
