#pragma once
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

class File_White{
public:
	static bool White_Save(const char* filename_, const char* stageName, const char* Name ,const int isClear);
};

