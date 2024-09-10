#include "HitBox.h"

HitBox::HitBox(){
}

Corners HitBox::PosUpDate(Vector2 pos, float radius, const int size){
	Corners returnCorners;

	returnCorners.LeftTop_.x = static_cast<int>((pos.x - (radius * 0.5f)) / static_cast<float>(size));
	returnCorners.LeftTop_.y = static_cast<int>((pos.y - (radius * 0.5f)) / static_cast<float>(size));
	returnCorners.RightTop_.x = static_cast<int>((pos.x + (radius * 0.5f) - 1) / static_cast<float>(size));
	returnCorners.RightTop_.y = static_cast<int>((pos.y - (radius * 0.5f)) / static_cast<float>(size));
	returnCorners.LeftBottom_.x = static_cast<int>((pos.x - (radius * 0.5f)) / static_cast<float>(size));
	returnCorners.LeftBottom_.y = static_cast<int>((pos.y + (radius * 0.5f) - 1) / static_cast<float>(size));
	returnCorners.RightBottom_.x = static_cast<int>((pos.x + (radius * 0.5f) - 1) / static_cast<float>(size));
	returnCorners.RightBottom_.y = static_cast<int>((pos.y + (radius * 0.5f) - 1) / static_cast<float>(size));

	return returnCorners;
}

bool HitBox::HitBox_(int** map, Corners corners, int returnMapA) {
	if (map[corners.LeftTop_.y][corners.LeftTop_.x] == returnMapA ||
		map[corners.RightTop_.y][corners.RightTop_.x] == returnMapA ||
		map[corners.LeftBottom_.y][corners.LeftBottom_.x] == returnMapA ||
		map[corners.RightBottom_.y][corners.RightBottom_.x] == returnMapA) {
		return 1;
	}
	else {
		return 0;
	}
}

IntVector2 HitBox::MapHitBox(Corners corners, int** Map, int returnMapA){
	if (Map[corners.LeftTop_.y][corners.LeftTop_.x] == returnMapA) {
		return corners.LeftTop_;
	}
	if (Map[corners.RightTop_.y][corners.RightTop_.x] == returnMapA) {
		return corners.RightTop_;
	}
	if (Map[corners.LeftBottom_.y][corners.LeftBottom_.x] == returnMapA) {
		return corners.LeftBottom_;
	}
	if (Map[corners.RightBottom_.y][corners.RightBottom_.x] == returnMapA) {
		return corners.RightBottom_;
	}

	IntVector2 returnMapB = {};
	return returnMapB;
}

bool HitBox::PlayerHitBox(Vector2 player_pos_, float player_radius_, Vector2 pos_, float radius){
	if (player_pos_.x + (player_radius_ * 0.5f) >= pos_.x - (radius * 0.5f) &&
		pos_.x + (radius * 0.5f) >= player_pos_.x - (player_radius_ * 0.5f)) {
		if (player_pos_.y + (player_radius_ * 0.5f) >= pos_.y - (radius * 0.5f) &&
			pos_.y + (radius * 0.5f) >= player_pos_.y - (player_radius_ * 0.5f)) {
			return true;
		}
	}
	return false;
}

bool HitBox::HitMouse_(Vector2 mouse, Vector2 pos_, Vector2 size_) {
	if (mouse.x >= pos_.x - (size_.x * 0.5f) && mouse.x <= pos_.x + (size_.x * 0.5f)) {
		if (mouse.y >= pos_.y - (size_.y * 0.5f) && mouse.y <= pos_.y + (size_.y * 0.5f)) {
			/*if (Novice::IsTriggerMouse(0)) {
				player->map->scene_ = Select;
			}*/
			return true;
		}
	}
	return false;
}

