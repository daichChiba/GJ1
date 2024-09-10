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
	Novice::Initialize(kWindowTitle, 640, 720);
	Player* player = new Player();

	Vector2 mouse = { 0.0f,0.0f };
	Button selectButton{
	Vector2(450.0f,700.0f),//高さ
	Vector2(200.0f,80.0f)//幅
	};
	Button firstButton{
		Vector2(64.0f,64.0f),//高さ
		Vector2(80.0f,80.0f)//幅
	};

	Scene_ scene;
	scene = titel;

	int mouseX = static_cast<int>(mouse.x);
	int mouseY = static_cast<int>(mouse.y);
	int WhiteGH_ = Novice::LoadTexture("white1x1.png");
	int mouseGH = Novice::LoadTexture("./Resource/sword1.png");


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

		switch (scene) {
		case titel:
			if (player->hitBox_->HitMouse_(mouse, selectButton.pos, selectButton.size)){
				if (Novice::IsTriggerMouse(0)){
					scene = Select;
				}
			}
			break;
		case Select:
			if (player->hitBox_->HitMouse_(mouse,firstButton.pos,firstButton.size)){
				if (Novice::IsTriggerMouse(0)) {
					scene = stage_1;
				}
			}
			break;
		case stage_1:
			player->Update(keys);
			player->map->Update();
			player->enemy_->Update();
			break;
		case gameClear:
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



		switch (scene) {
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
			Novice::DrawQuad(
			int(firstButton.pos.x - firstButton.size.x * 0.5f), int(firstButton.pos.y - firstButton.size.y * 0.5f),
			int(firstButton.pos.x + firstButton.size.x * 0.5f), int(firstButton.pos.y - firstButton.size.y * 0.5f),
			int(firstButton.pos.x - firstButton.size.x * 0.5f), int(firstButton.pos.y + firstButton.size.y * 0.5f),
			int(firstButton.pos.x + firstButton.size.x * 0.5f), int(firstButton.pos.y + firstButton.size.y * 0.5f),
			0, 0,
			int(firstButton.size.x), int(firstButton.size.y),
			WhiteGH_,
			BLACK
		);
			break;
		case stage_1:
			player->Draw();
			player->map->Draw();
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
