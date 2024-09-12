#include <Novice.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>
#include "Player.h"
#include "Scene.h"


const char kWindowTitle[] = "大脱獄";




// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 672, 720);
	Player* player = new Player();

	Vector2 mouse = { 0.0f,0.0f };
	Button selectButton{
	Vector2(450.0f,700.0f),//高さ
	Vector2(200.0f,80.0f)//幅
	};
	Button StageButton[15];
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 3; x++) {
			int index = y * 3 + x;
			StageButton[index].pos.x = 96.0f * x + 64.0f;
			StageButton[index].pos.y = 96.0f * y + 64.0f;
			StageButton[index].size.x = 32.0f;
			StageButton[index].size.y = 32.0f;
		}
	}

	bool isClick[15];

	Button ClearBotton[15];
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 3; x++) {
			int index = y * 3 + x;
			ClearBotton[index].pos.x = 96.0f * x + 64.0f;
			ClearBotton[index].pos.y = 96.0f * y + 64.0f + 64.0f;
			ClearBotton[index].size.x = 32.0f;
			ClearBotton[index].size.y = 32.0f;
		}
	}


	bool isClear[15];

	isClear[0] = File_Read::Read_Save("SaveData/stageClear.json", "firstStage", "isClear", "first stage isClear:");
	isClear[1] = File_Read::Read_Save("SaveData/stageClear.json", "secondStage", "isClear", "second stage isClear:");

	Scene_ scene;
	scene = titel;

	int mouseX = static_cast<int>(mouse.x);
	int mouseY = static_cast<int>(mouse.y);
	int WhiteGH_ = Novice::LoadTexture("white1x1.png");
	int mouseGH = Novice::LoadTexture("./Resource/tejou.png");


	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition(&mouseX, &mouseY);
		Novice::SetMouseCursorVisibility(0);


		///
		/// ↓更新処理ここから
		///

		mouse = Vector2(static_cast<float>(mouseX), static_cast<float>(mouseY));


		switch (player->enemy_->scene) {
		case titel:
			if (player->hitBox_->HitMouse_(mouse, selectButton.pos, selectButton.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = Select;
				}
			}
			break;
		case Select:
			for (int y = 0; y < 5; y++) {
				for (int x = 0; x < 3; x++) {
					int index = y * 3 + x;
					if (player->hitBox_->HitMouse_Scene(mouse, StageButton[index].pos, StageButton[index].size,isClick[index])) {
						if (isClick[0]){
							if (Novice::IsTriggerMouse(0)) {
								player->enemy_->scene = stage_1;
							}
						}
						if (isClick[1]){
							if (Novice::IsTriggerMouse(0)) {
								player->enemy_->scene = stage_2;
							}
						}
					}
				}
			}
			break;
		case stage_1:
			player->Update(keys);
			player->map->Update(player->enemy_->scene);
			player->enemy_->Update();
			break;
		case stage_2:
			player->Update(keys);
			player->map->Update(player->enemy_->scene);
			player->enemy_->Update();
			break;
		case gameClear:
			if (player->GetTmpScene() == stage_1) {
				player->clearSave(isClear[0]);
			}
			if (player->GetTmpScene()==stage_2){
				player->clearSave(isClear[1]);
			}
			break;
		case gameOver:
			break;

		}



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///



		switch (player->enemy_->scene) {
		case titel:
			Novice::DrawQuad(
				int(selectButton.pos.x - selectButton.size.x * 0.5f), int(selectButton.pos.y - selectButton.size.y * 0.5f),
				int(selectButton.pos.x + selectButton.size.x * 0.5f), int(selectButton.pos.y - selectButton.size.y * 0.5f),
				int(selectButton.pos.x - selectButton.size.x * 0.5f), int(selectButton.pos.y + selectButton.size.y * 0.5f),
				int(selectButton.pos.x + selectButton.size.x * 0.5f), int(selectButton.pos.y + selectButton.size.y * 0.5f),
				0, 0,
				int(selectButton.size.x), int(selectButton.size.y),
				WhiteGH_,
				BLACK
			);
			break;
		case Select:
			for (int y = 0; y < 5; y++) {
				for (int x = 0; x < 3; x++) {
					int index = y * 3 + x;
					Novice::DrawQuad(
						int(StageButton[index].pos.x - StageButton[index].size.x * 0.5f), int(StageButton[index].pos.y - StageButton[index].size.y * 0.5f),
						int(StageButton[index].pos.x + StageButton[index].size.x * 0.5f), int(StageButton[index].pos.y - StageButton[index].size.y * 0.5f),
						int(StageButton[index].pos.x - StageButton[index].size.x * 0.5f), int(StageButton[index].pos.y + StageButton[index].size.y * 0.5f),
						int(StageButton[index].pos.x + StageButton[index].size.x * 0.5f), int(StageButton[index].pos.y + StageButton[index].size.y * 0.5f),
						0, 0,
						int(StageButton[index].size.x), int(StageButton[index].size.y),
						WhiteGH_,
						BLACK
					);


				}
			}

			for (int i = 0; i < 15; i++) {
				if (isClear[i] == true) {
					Novice::DrawQuad(
						int(ClearBotton[i].pos.x - ClearBotton[i].size.x * 0.5f),
						int(ClearBotton[i].pos.y - ClearBotton[i].size.y * 0.5f),
						int(ClearBotton[i].pos.x + ClearBotton[i].size.x * 0.5f),
						int(ClearBotton[i].pos.y - ClearBotton[i].size.y * 0.5f),
						int(ClearBotton[i].pos.x - ClearBotton[i].size.x * 0.5f),
						int(ClearBotton[i].pos.y + ClearBotton[i].size.y * 0.5f),
						int(ClearBotton[i].pos.x + ClearBotton[i].size.x * 0.5f),
						int(ClearBotton[i].pos.y + ClearBotton[i].size.y * 0.5f),
						0, 0,
						int(ClearBotton[i].size.x), int(ClearBotton[i].size.y),
						WhiteGH_,
						WHITE
					);
					Novice::DrawBox(
						static_cast<int>(ClearBotton[i].pos.x - ClearBotton[i].size.x * 0.5f),
						static_cast<int>(ClearBotton[i].pos.y - ClearBotton[i].size.y * 0.5f),
						static_cast<int>(ClearBotton[i].size.x),
						static_cast<int>(ClearBotton[i].size.y),
						0.0f, BLACK, kFillModeWireFrame
					);
				}

			}
			break;
		case stage_1:
			player->map->Draw();
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_2:
			player->map->Draw();
			player->Draw();
			player->enemy_->Draw();
			break;
		case gameClear:
			break;
		case gameOver:
			break;

		}
		Novice::DrawSprite(
			static_cast<int>(mouse.x - 16.0f), static_cast<int>(mouse.y - 16.0f),
			mouseGH,
			1, 1,
			0.0f,
			WHITE
		);


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();


		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	// 動的メモリの解放
	for (int i = 0; i < MAX_HEIGHT; i++) {
		free(player->map->ppMap[i]);
	}
	free(player->map->ppMap);
	return 0;
}
