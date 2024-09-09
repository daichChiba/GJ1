#pragma once
#include "Corners.h"
#include "Vector2.h"
#include "HitBox.h"
#include"Map.h"

class Enemy{
public:
	Enemy();
	void Update();
	void Draw();
	HitBox* hitBox_ = new HitBox();
	Map* map = new Map();

	Vector2 GetPos_() { return pos_; }
	float GetRadius_() { return radius_; }


private:
	int EnemyGH;
	Vector2 pos_;
	Vector2 tmpPos_;
	float radius_;
	float speed_;
	float tmpSpeed;
	Corners corners_;
	Vector2 direction;
	Vector2 verocity;
	IntVector2 hitMapKeep = {};

	bool isWallCollision;

	int DirectionNumber = 1;
	int DirectionCount;



};

