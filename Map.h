#pragma once
#include"Novice.h"
#include"Vector2.h"
#include"LoadMapChip.h"
#include "Scene.h"
const int MapY_ = 21;
const int MapX_ = 21;
const int blockSize = 32;
class Map{
public:
	Map();
	LoadMapChip* loadMapChip_ = new LoadMapChip();
	void Update(Scene_ scene);
	void Draw();
	int** ppMap;


	Vector2 GetMapPos(int mapNumber);
	void SetMap(int** map, int mapNumber,int changeNumber);

private:
	int blockGH = Novice::LoadTexture("./Resource/brickBlock.png");
	int noSaveGH = Novice::LoadTexture("./Resource/Returnbutton.png");
	int backGroundGH = Novice::LoadTexture("./Resource/backGround.png");
	int GoalGH = Novice::LoadTexture("./Resource/door.png");

};

