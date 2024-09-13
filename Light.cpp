#include "Light.h"
#include <Novice.h>

Light::Light() {

}

void Light::Initialize() {
	
	//left = 0.0f;
	//right = 0.0f;
	//top = 0.0f;
	//bottom = 0.0f;

	/*w = 110.0f;
	h = 80.0f;*/

}

void Light::Update(int dir,Vector2 pos) {
	/*pos_ = enemy_->GetPos_();*/
	pos_ = pos;

	//右向き
	if (dir == 1) {
		pos_.x = pos.x + 20;
		pos_.y = pos.y - 10;
	}

	//左向き
	if (dir == 2) {
		pos_.x = pos.x - 70;
		pos_.y = pos.y - 10;
	}
	
	//上向き
	if (dir == 3) {
		pos_.x = pos.x-10;
		pos_.y = pos.y- 70;
	}

	//下向き
	if (dir == 4) {
		pos_.x = pos.x - 10;
		pos_.y = pos.y + 20;
	}

	/*left = pos_.x;
	right = pos_.x + w;
	top = pos_.y;
	bottom = pos_.y + h;*/

}

void Light::Draw(int dir) {
	
	//〇
	if (dir == 1) {//右向き
		//横//縦
		Novice::DrawBox(static_cast<int>(pos_.x - (radius_ * 0.5f)),
			static_cast<int>(pos_.y - (radius_ * 0.5f)),
			50, 20,
			0.0f, YELLOW - 0x66,
			kFillModeSolid);
	}
	//〇
	if (dir == 2) {//左向き
		//横//縦
		Novice::DrawBox(static_cast<int>(pos_.x - (radius_ * 0.5f)),
			static_cast<int>(pos_.y - (radius_ * 0.5f)),
			50, 20,
			0.0f,YELLOW - 0x66,
			kFillModeSolid);
	}
	//〇
	if (dir == 3) {//上向き
		//横//縦
		Novice::DrawBox(static_cast<int>(pos_.x - (radius_ * 0.5f))
			, static_cast<int>(pos_.y - (radius_ * 0.5f)),
			20, 50,
			0.0f, YELLOW - 0x66,
			kFillModeSolid);
	}
	//〇
	if (dir == 4) {//下向き
		//横//縦
		Novice::DrawBox(static_cast<int>(pos_.x - (radius_ * 0.5f)),
			static_cast<int>(pos_.y - (radius_ * 0.5f)),
			20, 50,
			0.0f, YELLOW - 0x66,
			kFillModeSolid);
	}


}


