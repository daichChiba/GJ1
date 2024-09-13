#pragma once
#include "Corners.h"
#include "Vector2.h"
#include "HitBox.h"
#include"Map.h"
#include "Scene.h"
#include "Light.h"


class Enemy{
public:
	Enemy(Vector2 pos);
	void Update();
	void Draw();
	HitBox* hitBox_ = new HitBox();
	Map* map = new Map();
	Scene_ scene = titel;
	Light* light = new Light();

	Vector2 GetPos_() { return pos_; }
	float GetRadius_() { return radius_; }
	Vector2 SetPos_(Vector2 pos) { return pos_ = pos; }
	bool SetIsAlive(bool isAlive_) { return isAlive = isAlive_; }
	bool GetIsAlive() { return isAlive; }
	float SetSpeed(float speed) { return speed_ = speed; }

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
	bool isAlive;



};

