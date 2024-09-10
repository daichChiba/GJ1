#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_WIDTH 20
#define MAX_HEIGHT 20
class LoadMapChip{
public:
	// マップチップのファイル読み込み
	int MapChipLood(int** map, const char* c);
};

