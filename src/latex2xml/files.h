#pragma once
#ifndef FILES_POLICY_UTILITIES_FOR_CHECKING_FILES 
#define FILES_POLICY_UTILITIES_FOR_CHECKING_FILES

class FilesPolicy
{
public:
	std::string getFileNameOnly (const std::string);
	bool fileExists (const std::string &);
}

#endif