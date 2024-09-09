#pragma once
#include"Vector2.h"
#include"Corners.h"
class HitBox{
public:
	HitBox();
	Corners PosUpDate(Vector2 pos, float radius, const int size);
	bool HitBox_(int** map, Corners corners, int returnMapA);
	IntVector2 MapHitBox(Corners corners, int** Map, int returnMapA);
	bool PlayerHitBox(Vector2 player_pos_, float player_radius_, Vector2 pos_, float radius);
};

