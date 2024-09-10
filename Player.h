#pragma once
#include "Corners.h"
#include "Vector2.h"
#include "HitBox.h"
#include"Map.h"
#include "Enemy.h"

class Player{
public:
	Player();
	void Update(char* keys/*, char* prekeys*/);
	void Draw();
	HitBox* hitBox_ = new HitBox();
	Map* map = new Map();
	Enemy* enemy_ = new Enemy();



private:
	int PlayerGH;
	Vector2 pos_;
	Vector2 tmpPos_;
	float radius_;
	float speed_;
	float tmpSpeed;
	Corners corners_;
	Vector2 direction;
	Vector2 verocity;
	IntVector2 hitMapKeep = {};
	bool isAlive;
	bool firstStageSave;
	bool isSave;

};

