﻿#include "Enemy.h"

Enemy::Enemy(){
	pos_ = { 400.0f,128.0f };//pos_
	verocity = { 0.0f,0.0f };//verocity
	direction = { 0.0f, 0.0f };//direction
	radius_ = 32.0f;//radius_
	speed_ = 4.0f;//speed_
	corners_ = {};//corners_
	tmpPos_ = { 0.0f,0.0f };
	tmpSpeed = 0.0f;
	EnemyGH = Novice::LoadTexture("./Resource/Knight.png");
	isWallCollision = false;

}

void Enemy::Update(){
	map->Update();
	//向きの初期化
	direction.x = 0.0f;
	direction.y = 0.0f;

	if (isWallCollision==false){
		if (DirectionNumber==1) {
			direction.x += 1.0f;
		}
		if (DirectionNumber == 2) {
			direction.x -= 1.0f;
		}
		if (DirectionNumber == 3) {
			direction.y -= 1.0f;
		}
		if (DirectionNumber == 4) {
			direction.y += 1.0f;
		}
	}
	if (isWallCollision){
		DirectionNumber = static_cast<int>(rand() % 4+1);
		isWallCollision = false;
	}


	//移動量の決定
	verocity.x = direction.x * float(speed_);
	verocity.y = direction.y * float(speed_);

	/*仮に移動させる
	  playerの座標の代入をして
　	 仮に動いたｘの計算をする*/
	tmpPos_ = pos_;
	tmpPos_.x += verocity.x;

	//当たり判定を取るために四辺の変数を代入する
	corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);

	if (hitBox_->HitBox_(map->ppMap, corners_, 1)) {
		hitMapKeep = hitBox_->MapHitBox(corners_, map->ppMap, 1);

		if (pos_.x < static_cast<float>(hitMapKeep.x * blockSize + blockSize)) {
			while (true) {
				tmpPos_.x -= 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 1)) {
					pos_.x = tmpPos_.x;
					isWallCollision = true;
					break;
				}
			}
		} else {
			while (true) {
				tmpPos_.x += 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 1)) {
					pos_.x = tmpPos_.x;
					isWallCollision = true;
					break;
				}
			}
		}
	} else {
		pos_.x = tmpPos_.x;
	}
	/*仮に移動させる
	  playerの座標の代入をして
　	 仮に動いたｘの計算をする*/
	tmpPos_ = pos_;
	tmpPos_.y += verocity.y;

	//当たり判定を取るために四辺の変数を代入する
	corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);

	if (hitBox_->HitBox_(map->ppMap, corners_, 1)) {
		hitMapKeep = hitBox_->MapHitBox(corners_, map->ppMap, 1);

		if (pos_.y < static_cast<float>(hitMapKeep.y * blockSize + blockSize)) {
			while (true) {
				tmpPos_.y -= 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 1)) {
					pos_.y = tmpPos_.y;
					isWallCollision = true;
					break;
				}
			}
		} else {
			while (true) {
				tmpPos_.y += 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 1)) {
					pos_.y = tmpPos_.y;
					isWallCollision = true;
					break;
				}
			}
		}
	} else {
		pos_.y = tmpPos_.y;
	}


}

void Enemy::Draw(){
	Novice::DrawSprite(
		static_cast<int>(pos_.x - (radius_ * 0.5f)), static_cast<int>(pos_.y - (radius_ * 0.5f)),
		EnemyGH,
		1.0f, 1.0f,
		0.0f,
		WHITE
	);
	Novice::DrawBox(
		static_cast<int>(pos_.x - (radius_ * 0.5f)), static_cast<int>(pos_.y - (radius_ * 0.5f)),
		static_cast<int>(radius_), static_cast<int>(radius_),
		0.0f, BLACK, kFillModeWireFrame
	);

	if (isWallCollision==false){
		Novice::ScreenPrintf(0, 640, "isWallCollision=false");
	} else{
		Novice::ScreenPrintf(0, 640, "isWallCollision=true");
	}
}
