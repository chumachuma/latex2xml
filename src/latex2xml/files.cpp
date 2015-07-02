#include "stdafx.h"

#include "files.h"
#include <fstream>

std::string FilesPolicy::getFileNameOnly (std::string fileName)
{
	int dotIndex = fileName.find_first_of(".");
	if ( dotIndex == std::string::npos )
		return fileName;
	else
		return fileName.substr(0, dotIndex);
}

bool FilesPolicy::fileExists (const std::string &filePath)
{
	std::ifstream isFile (filePath.c_str());
	return isFile;
}