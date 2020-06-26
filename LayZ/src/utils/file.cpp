#include "utils/file.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>

namespace lyz { namespace utils {

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

} }