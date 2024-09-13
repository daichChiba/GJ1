#pragma once
#include"Vector2.h"

enum Scene_ {
	titel,
	rule,
	Select,
	stage_1,
	stage_2,
	stage_3,
	stage_4,
	stage_5,
	stage_6,
	stage_7,
	stage_8,
	stage_9,
	stage_10,
	stage_11,
	stage_12,
	stage_13,
	stage_14,
	stage_15,
	gameClear,
	gameOver
};

struct Button {
	Vector2 pos;
	Vector2 size;
};


void DrawButton(Button button, int Gh);
void DrawButton(Button button, int Gh,int color);
void SpriteDraw(Vector2 pos, int Gh, int color);