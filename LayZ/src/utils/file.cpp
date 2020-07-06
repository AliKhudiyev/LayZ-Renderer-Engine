#include "utils/file.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>

namespace lyz { namespace utils {

	const char FileParser::fileTypeBegin = '<';
	const char FileParser::fileTypeEnd = '>';

	FileParser::FileParser()
	{
	}

	FileParser::~FileParser()
	{
	}

	std::string FileParser::read(const std::string & filepath)
	{
		std::ostringstream context;
		std::string line;
		std::ifstream file(filepath);
		if (!file) {
			std::cerr << "ERROR[fileparser]: Cannot open the file: " 
				<< filepath << std::endl;
			assert(false);
		}

		while (std::getline(file, line))
			context << line << '\n';

		file.close();
		return context.str();
	}

	std::vector<std::string> FileParser::mread(const std::string & filepath)
	{
		std::vector<std::string> mcontext;
		std::string context = FileParser::read(filepath);

		std::string type_specifier = std::string(1, FileParser::fileTypeBegin);
		type_specifier += std::string(1, FileParser::fileTypeEnd);

		std::string vertex_type = type_specifier;			vertex_type.insert(1, "VERTEX SHADER");
		std::string geometry_type = type_specifier;			geometry_type.insert(1, "GEOMETRY SHADER");
		std::string rasterization_type = type_specifier;	rasterization_type.insert(1, "RASTERIZATION SHADER");
		std::string fragment_type = type_specifier;			fragment_type.insert(1, "FRAGMENT SHADER");
		
		auto vertex_line = context.find(vertex_type);
		auto geometry_line = context.find(geometry_type);
		auto rasterization_line = context.find(rasterization_type);
		auto fragment_line = context.find(fragment_type);

		if (vertex_line == std::string::npos ||
			geometry_line == std::string::npos ||
			rasterization_line == std::string::npos ||
			fragment_line == std::string::npos) {
			
			std::cerr << "ERROR[fileparser]: reading multiple file types failed!\n";
			assert(false);
		}

		size_t vline = vertex_line, vsize = geometry_line - vertex_line - vertex_type.size();
		size_t gline = geometry_line, gsize = rasterization_line - geometry_line - geometry_type.size();
		size_t rline = rasterization_line, rsize = fragment_line - rasterization_line - rasterization_type.size();
		size_t fline = fragment_line, fsize = context.size() - fragment_type.size();

		mcontext.push_back(context.substr(vline + vertex_type.size(), vsize));
		mcontext.push_back(context.substr(gline + geometry_type.size(), gsize));
		mcontext.push_back(context.substr(rline + rasterization_type.size(), rsize));
		mcontext.push_back(context.substr(fline + fragment_type.size(), fsize));

		unsigned i = 0;
		for (auto& cntxt : mcontext) {
			if (cntxt.find_first_not_of(' ') != std::string::npos) {
				if (cntxt.find_first_not_of('\n') == std::string::npos) {
					cntxt = "";
				}
			}
		}

		/*std::cout << "VERTEX============\n=" << mcontext[0] << "\n\n";
		std::cout << "GEOMETRY============\n=" << mcontext[1] << "\n\n";
		std::cout << "RASTERIZATION============\n=" << mcontext[2] << "\n\n";
		std::cout << "FRAGMENT============\n=" << mcontext[3] << "\n\n";*/

		return mcontext;
	}

} }