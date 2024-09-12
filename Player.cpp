#include "Player.h"
#include"Novice.h"
#include"File_Read.h"
#include"File_White.h"


Player::Player() {
	pos_ = { 400.0f,64.0f };//pos_
	verocity = { 0.0f,0.0f };//verocity
	direction = { 0.0f, 0.0f };//direction
	radius_ = 32.0f;//radius_
	speed_ = 4.0f;//speed_
	corners_ = {};//corners_
	tmpPos_ = { 0.0f,0.0f };
	tmpSpeed = 0.0f;
	PlayerGH = Novice::LoadTexture("./Resource/player.png");
	isAlive = true;
	isSave = false;
	firstStageSave = File_Read::Read_Save("SaveData/stageSave.json", "firstStage", "isSave", "first stage isClear:");
	DeathCountor = 60;
	isClear = false;
}

void Player::Update(char* keys) {
	map->Update(enemy_->scene);
	//向きの初期化
	direction.x = 0.0f;
	direction.y = 0.0f;

	if (isAlive){
		if (keys[DIK_D]) {
			direction.x += 1.0f;
		}
		if (keys[DIK_A]) {
			direction.x -= 1.0f;
		}
		if (keys[DIK_W]) {
			direction.y -= 1.0f;
		}
		if (keys[DIK_S]) {
			direction.y += 1.0f;
		}
	}

	//移動量の決定
	verocity.x = direction.x * float(speed_);
	verocity.y = direction.y * float(speed_);

	if (firstStageSave){
		isSave = true;
	}

	if (isSave==true){
		//map->SetMap(map->ppMap, 3, 4);

		if (firstStageSave == false){
			firstStageSave = File_White::White_Save("SaveData/stageSave.json", "firstStage", "isSave", 1);
		}
	}

	if (isAlive==false){
		DeathCountor -= 1;
	}

	if (DeathCountor<=0){
		isAlive = true;
		DeathCountor = 60;
		if (isSave==true){
			pos_ = map->GetMapPos(3);
		}
	}

	if (isClear==true){
		enemy_->scene = gameClear;
	}

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
					break;
				}
			}
		} else {
			while (true) {
				tmpPos_.x += 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 1)) {
					pos_.x = tmpPos_.x;
					break;
				}
			}
		}
	} else {
		pos_.x = tmpPos_.x;
	}

	if (hitBox_->HitBox_(map->ppMap, corners_, 3)) {
		hitMapKeep = hitBox_->MapHitBox(corners_, map->ppMap, 3);

		if (pos_.x < static_cast<float>(hitMapKeep.x * blockSize + blockSize)) {
			while (true) {


				tmpPos_.x -= 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 3)) {
					pos_.x = tmpPos_.x;
					if (isSave == false) {
						isSave = true;
					}
					break;
				}
			}
		} else {
			while (true) {
				if (isSave == false) {
					isSave = true;
				}
				tmpPos_.x += 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 3)) {
					pos_.x = tmpPos_.x;
					break;
				}
			}
		}
	} else {
		pos_.x = tmpPos_.x;
	}

	//goalの当たり判定
	if (hitBox_->HitBox_(map->ppMap, corners_, 4)) {
		hitMapKeep = hitBox_->MapHitBox(corners_, map->ppMap, 4);

		if (pos_.x < static_cast<float>(hitMapKeep.x * blockSize + blockSize)) {
			while (true) {


				tmpPos_.x -= 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 4)) {
					pos_.x = tmpPos_.x;
					if (isClear == false) {
						isClear = true;
					}
					break;
				}
			}
		} else {
			while (true) {
				if (isClear == false) {
					isClear = true;
				}
				tmpPos_.x += 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 4)) {
					pos_.x = tmpPos_.x;
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
					break;
				}
			}
		} else {
			while (true) {
				tmpPos_.y += 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 1)) {
					pos_.y = tmpPos_.y;
					break;
				}
			}
		}
	} else {
		pos_.y = tmpPos_.y;
	}

	//クリアの当たり判定
	if (hitBox_->HitBox_(map->ppMap, corners_, 4)) {
		hitMapKeep = hitBox_->MapHitBox(corners_, map->ppMap, 4);

		if (pos_.y < static_cast<float>(hitMapKeep.y * blockSize + blockSize)) {
			while (true) {
				if (isClear == false) {
					isClear = true;
				}
				tmpPos_.y -= 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 4)) {
					pos_.y = tmpPos_.y;
					break;
				}
			}
		} else {
			while (true) {
				if (isClear == false) {
					isClear = true;
				}
				tmpPos_.y += 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 4)) {
					pos_.y = tmpPos_.y;
					break;
				}
			}
		}
	} else {
		pos_.y = tmpPos_.y;
	}	if (hitBox_->HitBox_(map->ppMap, corners_, 4)) {
		hitMapKeep = hitBox_->MapHitBox(corners_, map->ppMap, 4);

		if (pos_.y < static_cast<float>(hitMapKeep.y * blockSize + blockSize)) {
			while (true) {
				if (isClear == false) {
					isClear = true;
				}
				tmpPos_.y -= 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 4)) {
					pos_.y = tmpPos_.y;
					break;
				}
			}
		} else {
			while (true) {
				if (isClear == false) {
					isClear = true;
				}
				tmpPos_.y += 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 4)) {
					pos_.y = tmpPos_.y;
					break;
				}
			}
		}
	} else {
		pos_.y = tmpPos_.y;
	}




	if (hitBox_->PlayerHitBox(pos_, radius_, enemy_->GetPos_(), enemy_->GetRadius_())){
		isAlive = false;
	}
}

void Player::Draw() {
	if (isAlive){
		Novice::DrawSprite(
			static_cast<int>(pos_.x - (radius_ * 0.5f)), static_cast<int>(pos_.y - (radius_ * 0.5f)),
			PlayerGH,
			1.0f, 1.0f,
			0.0f,
			WHITE
		);
	}
	Novice::DrawBox(
		static_cast<int>(pos_.x - (radius_ * 0.5f)), static_cast<int>(pos_.y - (radius_ * 0.5f)),
		static_cast<int>(radius_), static_cast<int>(radius_),
		0.0f, BLACK, kFillModeWireFrame
	);
	if (isAlive == false) {
		Novice::ScreenPrintf(0, 660, "isAlive=false");
	} else {
		Novice::ScreenPrintf(0, 660, "isAlive=true");
	}
	if (isSave == false) {
		Novice::ScreenPrintf(0, 700, "isSave=false");
	} else {
		Novice::ScreenPrintf(0, 700, "isSave=true");
	}
	Novice::ScreenPrintf(100, 660, "DeathCountor=%d",DeathCountor);
	if (isClear == false) {
		Novice::ScreenPrintf(200, 700, "isClear=false");
	} else {
		Novice::ScreenPrintf(200, 700, "isClear=true");
	}
}
