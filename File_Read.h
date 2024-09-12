#pragma once
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
class File_Read{
public:
	static bool Read_Save(const char* filename_, const char* stageName, const char* isChar, const char* stageCount_);
};

