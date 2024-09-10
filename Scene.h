#pragma once
#include"Vector2.h"

enum Scene_ {
	titel,
	/*rule,*/
	Select,
	stage_1,
	//stage_2,
	//stage_3,
	gameClear,
	gameOver
};

struct Button {
	Vector2 pos;
	Vector2 size;
};
