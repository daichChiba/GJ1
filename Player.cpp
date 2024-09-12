#include "Player.h"
#include"Novice.h"



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
	StageSave = 0;
	DeathCountor = 60;
	isClear = false;
	tmpScene = 0;
}

void Player::Update(char* keys) {
	map->Update(enemy_->scene);
	if (enemy_->scene == stage_1) {
		StageSave = File_Read::Read_Save("SaveData/savePoint.json", "firstStage", "isSave", "first stage isSave:");
	}
	if (enemy_->scene == stage_1) {
		StageSave = File_Read::Read_Save("SaveData/savePoint.json", "secondStage", "isSave", "second stage isSave:");
	}

	//向きの初期化
	direction.x = 0.0f;
	direction.y = 0.0f;

	if (isAlive){
		if (keys[DIK_D]||keys[DIK_RIGHT]) {
			direction.x += 1.0f;
		}
		if (keys[DIK_A]||keys[DIK_LEFT]) {
			direction.x -= 1.0f;
		}
		if (keys[DIK_W]||keys[DIK_UP]) {
			direction.y -= 1.0f;
		}
		if (keys[DIK_S]||keys[DIK_DOWN]) {
			direction.y += 1.0f;
		}
	}

	//移動量の決定
	verocity.x = direction.x * float(speed_);
	verocity.y = direction.y * float(speed_);

	if (StageSave){
		isSave = true;
	}

	if (isSave==true){
		//map->SetMap(map->ppMap, 3, 4);

		if (StageSave == false){
			if (enemy_->scene == stage_1) {
				StageSave = File_White::White_Save("SaveData/savePoint.json", "firstStage", "isSave", 1);
			}
			if (enemy_->scene == stage_2) {
				StageSave = File_White::White_Save("SaveData/savePoint.json", "secondStage", "isSave", 1);
			}
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
		if (enemy_->scene == stage_1) {
			tmpScene = stage_1;
		}
		if (enemy_->scene == stage_2) {
			tmpScene = stage_2;
		}

		map->ResetMap(map->ppMap);
		
		enemy_->scene = gameClear;
		pos_ = { 400.0f,64.0f };
		enemy_->SetPos_(Vector2{ 400.0f, 128.0f });
		if (enemy_->scene == stage_1) {
			StageSave = File_White::White_Save("SaveData/savePoint.json", "firstStage", "isSave", 0);
		}
		if (enemy_->scene == stage_2) {
			StageSave = File_White::White_Save("SaveData/savePoint.json", "secondStage", "isSave", 0);
		}
		isClear = false;
		isSave = false;
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
	if (hitBox_->HitBox_(map->ppMap, corners_, 3)) {
		hitMapKeep = hitBox_->MapHitBox(corners_, map->ppMap, 3);

		if (pos_.y < static_cast<float>(hitMapKeep.y * blockSize + blockSize)) {
			while (true) {
				if (isSave == false) {
					isSave = true;
				}
				tmpPos_.y -= 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 3)) {
					pos_.y = tmpPos_.y;
					break;
				}
			}
		} else {
			while (true) {
				if (isSave == false) {
					isSave = true;
				}
				tmpPos_.y += 0.1f;
				corners_ = hitBox_->PosUpDate(tmpPos_, radius_, blockSize);
				if (!hitBox_->HitBox_(map->ppMap, corners_, 3)) {
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

void Player::clearSave(bool isClear_){
	if (tmpScene == stage_1) {
		isClear_ = File_White::White_Save("SaveData/stageClear.json", "firstStage", "isClear", 1);
	}
	if (tmpScene == stage_2) {
		isClear_ = File_White::White_Save("SaveData/stageClear.json", "secondStage", "isClear", 1);
	}
}
