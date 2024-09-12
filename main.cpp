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
	Button titelButton{
	Vector2(450.0f,700.0f),//高さ
	Vector2(200.0f,80.0f)//幅
	};


	Button Stage_1st{
	Vector2(144.0f,85.33f),//高さ
	Vector2(64.0f,64.0f)//幅
	};
	Button Stage_2nd{
	Vector2(320.0f,85.33f),//高さ
	Vector2(64.0f,64.0f)//幅
	};
	Button Stage_3rd{
	Vector2(496.0f,85.33f),//高さ
	Vector2(64.0f,64.0f)//幅
	};
	Button Stage_4th{
	Vector2(144.0f,202.67f),//高さ
	Vector2(64.0f,64.0f)//幅
	};
	Button Stage_5th{
	Vector2(320.0f,202.67f),//高さ
	Vector2(64.0f,64.0f)//幅
	};
	Button Stage_6th{
	Vector2(496.0f,202.67f),//高さ
	Vector2(64.0f,64.0f)//幅
	};
	Button Stage_7th{
	Vector2(144.0f,320.0f),//高さ
	Vector2(64.0f,64.0f)//幅
	};
	Button Stage_8th{
	Vector2(320.0f,320.0f),//高さ
	Vector2(64.0f,64.0f)//幅
	};
	Button Stage_9th{
	Vector2(496.0f,320.0f),//高さ
	Vector2(64.0f,64.0f)//幅
	};
	Button Stage_10th{
	Vector2(144.0f,437.33f),//高さ
	Vector2(64.0f,64.0f)//幅
	};
	Button Stage_11th{
	Vector2(320.0f,437.33f),//高さ
	Vector2(64.0f,64.0f)//幅
	};
	Button Stage_12th{
	Vector2(496.0f,437.33f),//高さ
	Vector2(64.0f,64.0f)//幅
	};
	Button Stage_13th{
	Vector2(144.0f,554.67f),//高さ
	Vector2(64.0f,64.0f)//幅
	};
	Button Stage_14th{
	Vector2(320.0f,554.67f),//高さ
	Vector2(64.0f,64.0f)//幅
	};
	Button Stage_15th{
	Vector2(496.0f,554.67f),//高さ
	Vector2(64.0f,64.0f)//幅
	};

	Button ClearBotton[15];
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 3; x++) {
			int index = y * 3 + x;
			ClearBotton[index].pos.x = 176.0f * x + 144.0f;
			ClearBotton[index].pos.y = 118.0f * y + 144.0f;
			ClearBotton[index].size.x = 32.0f;
			ClearBotton[index].size.y = 32.0f;
		}
	}


	bool isClear[15];


	Scene_ scene;
	scene = titel;

	int mouseX = static_cast<int>(mouse.x);
	int mouseY = static_cast<int>(mouse.y);
	int WhiteGH_ = Novice::LoadTexture("white1x1.png");
	int mouseGH = Novice::LoadTexture("./Resource/tejou.png");
	int clearGH = Novice::LoadTexture("./Resource/Star.png");


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
			isClear[0] = File_Read::Read_Save("SaveData/stageClear.json", "firstStage", "isClear", "first stage isClear:");
			isClear[1] = File_Read::Read_Save("SaveData/stageClear.json", "secondStage", "isClear", "second stage isClear:");

			if (player->hitBox_->HitMouse_(mouse, Stage_1st.pos, Stage_1st.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_1;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, Stage_2nd.pos, Stage_2nd.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_2;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, Stage_3rd.pos, Stage_3rd.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_3;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, Stage_4th.pos, Stage_4th.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_4;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, Stage_5th.pos, Stage_5th.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_5;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, Stage_6th.pos, Stage_6th.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_6;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, Stage_7th.pos, Stage_7th.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_7;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, Stage_8th.pos, Stage_8th.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_8;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, Stage_9th.pos, Stage_9th.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_9;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, Stage_10th.pos, Stage_10th.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_10;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, Stage_11th.pos, Stage_11th.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_11;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, Stage_12th.pos, Stage_12th.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_12;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, Stage_13th.pos, Stage_13th.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_13;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, Stage_14th.pos, Stage_14th.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_14;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, Stage_15th.pos, Stage_15th.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = stage_15;
				}
			}
			break;
		case stage_1:
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
			break;
		case stage_2:
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
			break;
		case stage_3:
			break;
		case stage_4:
			break;
		case stage_5:
			break;
		case stage_6:
			break;
		case stage_7:
			break;
		case stage_8:
			break;
		case stage_9:
			break;
		case stage_10:
			break;
		case stage_11:
			break;
		case stage_12:
			break;
		case stage_13:
			break;
		case stage_14:
			break;
		case stage_15:
			break;
		case gameClear:
			if (player->hitBox_->HitMouse_(mouse, titelButton.pos, titelButton.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = titel;
				}
			}
			if (player->GetTmpScene() == stage_1) {
				player->clearSave(isClear[0]);
			}
			if (player->GetTmpScene() == stage_2) {
				player->clearSave(isClear[1]);
			}
			break;
		case gameOver:
			if (player->hitBox_->HitMouse_(mouse, titelButton.pos, titelButton.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = titel;
				}
			}
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
			Novice::DrawSprite(0, 0, player->map->GetBackGroundGH(), 1.0f, 1.0f, 0.0f, WHITE);
			DrawButton(Stage_1st, WhiteGH_);
			DrawButton(Stage_2nd, WhiteGH_);
			DrawButton(Stage_3rd, WhiteGH_);
			DrawButton(Stage_4th, WhiteGH_);
			DrawButton(Stage_5th, WhiteGH_);
			DrawButton(Stage_6th, WhiteGH_);
			DrawButton(Stage_7th, WhiteGH_);
			DrawButton(Stage_8th, WhiteGH_);
			DrawButton(Stage_9th, WhiteGH_);
			DrawButton(Stage_10th, WhiteGH_);
			DrawButton(Stage_11th, WhiteGH_);
			DrawButton(Stage_12th, WhiteGH_);
			DrawButton(Stage_13th, WhiteGH_);
			DrawButton(Stage_14th, WhiteGH_);
			DrawButton(Stage_15th, WhiteGH_);

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
						clearGH,
						WHITE
					);

				}
				Novice::DrawBox(
					static_cast<int>(ClearBotton[i].pos.x - (ClearBotton[i].size.x * 0.5f)),
					static_cast<int>(ClearBotton[i].pos.y - (ClearBotton[i].size.y * 0.5f)),
					static_cast<int>(ClearBotton[i].size.x),
					static_cast<int>(ClearBotton[i].size.y),
					0.0f, BLACK, kFillModeWireFrame
				);
			}
			//if (isClick[0] == true) {
			//	Novice::ScreenPrintf(0, 680, "isClick[0]=true");
			//} else {
			//	Novice::ScreenPrintf(0, 680, "isClick[0]=else");
			//}
			break;
		case stage_1:
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_2:
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_3:
			break;
		case stage_4:
			break;
		case stage_5:
			break;
		case stage_6:
			break;
		case stage_7:
			break;
		case stage_8:
			break;
		case stage_9:
			break;
		case stage_10:
			break;
		case stage_11:
			break;
		case stage_12:
			break;
		case stage_13:
			break;
		case stage_14:
			break;
		case stage_15:
			break;
		case gameClear:
			Novice::DrawQuad(
				int(titelButton.pos.x - titelButton.size.x * 0.5f), int(titelButton.pos.y - titelButton.size.y * 0.5f),
				int(titelButton.pos.x + titelButton.size.x * 0.5f), int(titelButton.pos.y - titelButton.size.y * 0.5f),
				int(titelButton.pos.x - titelButton.size.x * 0.5f), int(titelButton.pos.y + titelButton.size.y * 0.5f),
				int(titelButton.pos.x + titelButton.size.x * 0.5f), int(titelButton.pos.y + titelButton.size.y * 0.5f),
				0, 0,
				int(titelButton.size.x), int(titelButton.size.y),
				WhiteGH_,
				BLACK
			);
			if (player->GetTmpScene() == stage_1) {
				Novice::ScreenPrintf(200, 680, "tmpScene=stage_1");
			}
			if (player->GetTmpScene()==stage_2) {
				Novice::ScreenPrintf(200, 680, "tmpScene=stage_2");
			}

			break;
		case gameOver:
			Novice::DrawQuad(
				int(titelButton.pos.x - titelButton.size.x * 0.5f), int(titelButton.pos.y - titelButton.size.y * 0.5f),
				int(titelButton.pos.x + titelButton.size.x * 0.5f), int(titelButton.pos.y - titelButton.size.y * 0.5f),
				int(titelButton.pos.x - titelButton.size.x * 0.5f), int(titelButton.pos.y + titelButton.size.y * 0.5f),
				int(titelButton.pos.x + titelButton.size.x * 0.5f), int(titelButton.pos.y + titelButton.size.y * 0.5f),
				0, 0,
				int(titelButton.size.x), int(titelButton.size.y),
				WhiteGH_,
				BLACK
			);
			break;

		}
		Novice::DrawSprite(
			static_cast<int>(mouse.x - 16.0f), static_cast<int>(mouse.y - 16.0f),
			mouseGH,
			1, 1,
			0.0f,
			WHITE
		);
		if (player->enemy_->scene == titel) {
			Novice::ScreenPrintf(200, 680, "scene=titel");
		}
		if (player->enemy_->scene == Select) {
			Novice::ScreenPrintf(200, 680, "scene=Select");
		}
		if (player->enemy_->scene == stage_1) {
			Novice::ScreenPrintf(200, 680, "scene=stage_1");
		}
		if (player->enemy_->scene == stage_2) {
			Novice::ScreenPrintf(200, 680, "scene=stage_2");
		}


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
