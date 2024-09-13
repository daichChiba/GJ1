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
	Novice::Initialize(kWindowTitle, 672, 672);
	Player* player = new Player();


	Vector2 mouse = { 0.0f,0.0f };
	Button continueButton{
	Vector2(140.0f,600.0f),//高さ
	Vector2(200.0f,80.0f)//幅
	};
	Button AllResetButton{
	Vector2(340.0f,600.0f),//高さ
	Vector2(200.0f,80.0f)//幅
	};
	Button titelButton{
	Vector2(450.0f,600.0f),//高さ
	Vector2(200.0f,80.0f)//幅
	};
	Button RuleButton{
	Vector2(540.0f,600.0f),//高さ
	Vector2(200.0f,80.0f)//幅
	};

	Button XButton{
		Vector2(16.0f,16.0f),
		Vector2(32.0f,32.0f)
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
	int number1GH = Novice::LoadTexture("./Resource/1.png");
	int number2GH = Novice::LoadTexture("./Resource/2.png");
	int number3GH = Novice::LoadTexture("./Resource/3.png");
	int number4GH = Novice::LoadTexture("./Resource/4.png");
	int number5GH = Novice::LoadTexture("./Resource/5.png");
	int number6GH = Novice::LoadTexture("./Resource/6.png");
	int number7GH = Novice::LoadTexture("./Resource/7.png");
	int number8GH = Novice::LoadTexture("./Resource/8.png");
	int number9GH = Novice::LoadTexture("./Resource/9.png");
	int number10GH = Novice::LoadTexture("./Resource/10.png");
	int number11GH = Novice::LoadTexture("./Resource/11.png");
	int number12GH = Novice::LoadTexture("./Resource/12.png");
	int number13GH = Novice::LoadTexture("./Resource/13.png");
	int number14GH = Novice::LoadTexture("./Resource/14.png");
	int number15GH = Novice::LoadTexture("./Resource/15.png");

	int titelGH = Novice::LoadTexture("./Resource/titel.png");
	int GameOverGH = Novice::LoadTexture("./Resource/GameOver.png");
	int GameClearGH = Novice::LoadTexture("./Resource/GameClear.png");
	int continueGH = Novice::LoadTexture("./Resource/continuation.png");
	int AllResetGH = Novice::LoadTexture("./Resource/allReset.png");
	int RuleButtonGH = Novice::LoadTexture("./Resource/explan.png");
	int RuleGH = Novice::LoadTexture("./Resource/explanation.png");
	int XGH = Novice::LoadTexture("./Resource/X.png");
	int titelButtonGH = Novice::LoadTexture("./Resource/titleBottan.png");


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
			if (player->hitBox_->HitMouse_(mouse, continueButton.pos, continueButton.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = Select;
				}
			}
			if (player->hitBox_->HitMouse_(mouse, AllResetButton.pos, AllResetButton.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = Select;
					isClear[0] = File_White::White_Save("SaveData/stageClear.json", "firstStage", "isClear", 0);
					isClear[1] = File_White::White_Save("SaveData/stageClear.json", "secondStage", "isClear", 0);
					isClear[2] = File_White::White_Save("SaveData/stageClear.json", "thirdStage", "isClear", 0);
					isClear[3] = File_White::White_Save("SaveData/stageClear.json", "fourthStage", "isClear", 0);
					isClear[4] = File_White::White_Save("SaveData/stageClear.json", "fifthStage", "isClear", 0);
					isClear[5] = File_White::White_Save("SaveData/stageClear.json", "sixthStage", "isClear", 0);
					isClear[6] = File_White::White_Save("SaveData/stageClear.json", "seventhStage", "isClear", 0);
					isClear[7] = File_White::White_Save("SaveData/stageClear.json", "eighthStage", "isClear", 0);
					isClear[8] = File_White::White_Save("SaveData/stageClear.json", "ninthStage", "isClear", 0);
					isClear[9] = File_White::White_Save("SaveData/stageClear.json", "tenthStage", "isClear", 0);
					isClear[10] = File_White::White_Save("SaveData/stageClear.json", "eleventhStage", "isClear", 0);
					isClear[11] = File_White::White_Save("SaveData/stageClear.json", "twelfthStage", "isClear", 0);
					isClear[12] = File_White::White_Save("SaveData/stageClear.json", "thirteenthStage", "isClear", 0);
					isClear[13] = File_White::White_Save("SaveData/stageClear.json", "fourteenthStage", "isClear", 0);
					isClear[14] = File_White::White_Save("SaveData/stageClear.json", "fifteenthStage", "isClear", 0);

					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "firstStage", "isSave", 0));
					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "secondStage", "isSave", 0))  ;
					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "thirdStage", "isSave", 0))  ;
					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "fourthStage", "isSave", 0))  ;
					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "fifthStage", "isSave", 0))  ;
					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "sixthStage", "isSave", 0))  ;
					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "seventhStage", "isSave", 0))  ;
					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "eighthStage", "isSave", 0))  ;
					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "ninthStage", "isSave", 0))  ;
					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "tenthStage", "isSave", 0))  ;
					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "eleventhStage", "isSave", 0))  ;
					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "twelfthStage", "isSave", 0))  ;
					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "thirteenthStage", "isSave", 0))  ;
					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "fourteenthStage", "isSave", 0))  ;
					player->SetIsSave(File_White::White_Save("SaveData/savePoint.json", "fifteenthStage", "isSave", 0))  ;

				}
			}
			if (player->hitBox_->HitMouse_(mouse, RuleButton.pos, RuleButton.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = rule;
				}
			}
			break;

		case rule:
			if (player->hitBox_->HitMouse_(mouse, XButton.pos, XButton.size)) {
				if (Novice::IsTriggerMouse(0)) {
					player->enemy_->scene = titel;
				}
			}
			break;

		case Select:
			isClear[0] = File_Read::Read_Save("SaveData/stageClear.json", "firstStage", "isClear", "first stage isClear:");
			isClear[1] = File_Read::Read_Save("SaveData/stageClear.json", "secondStage", "isClear", "second stage isClear:");
			isClear[2] = File_Read::Read_Save("SaveData/stageClear.json", "thirdStage", "isClear", "third stage isClear:");
			isClear[3] = File_Read::Read_Save("SaveData/stageClear.json", "fourthStage", "isClear", "fourth stage isClear:");
			isClear[4] = File_Read::Read_Save("SaveData/stageClear.json", "fifthStage", "isClear", "fifth stage isClear:");
			isClear[5] = File_Read::Read_Save("SaveData/stageClear.json", "sixthStage", "isClear", "sixth stage isClear:");
			isClear[6] = File_Read::Read_Save("SaveData/stageClear.json", "seventhStage", "isClear", "seventh stage isClear:");
			isClear[7] = File_Read::Read_Save("SaveData/stageClear.json", "eighthStage", "isClear", "eighth stage isClear:");
			isClear[8] = File_Read::Read_Save("SaveData/stageClear.json", "ninthStage", "isClear", "ninth stage isClear:");
			isClear[9] = File_Read::Read_Save("SaveData/stageClear.json", "tenthStage", "isClear", "tenth stage isClear:");
			isClear[10] = File_Read::Read_Save("SaveData/stageClear.json", "eleventhStage", "isClear", "eleventh stage isClear:");
			isClear[11] = File_Read::Read_Save("SaveData/stageClear.json", "twelfthStage", "isClear", "twelfth stage isClear:");
			isClear[12] = File_Read::Read_Save("SaveData/stageClear.json", "thirteenthStage", "isClear", "thirteenth stage isClear:");
			isClear[13] = File_Read::Read_Save("SaveData/stageClear.json", "fourteenthStage", "isClear", "fourteenth stage isClear:");
			isClear[14] = File_Read::Read_Save("SaveData/stageClear.json", "fifteenthStage", "isClear", "fifteenth stage isClear:");


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
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
			break;
		case stage_4:
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
			break;
		case stage_5:
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
			break;
		case stage_6:
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
			break;
		case stage_7:
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
			break;
		case stage_8:
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
			break;
		case stage_9:
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
			break;
		case stage_10:
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
			break;
		case stage_11:
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
			break;
		case stage_12:
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
			break;
		case stage_13:
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
			break;
		case stage_14:
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
			break;
		case stage_15:
			player->map->Update(player->enemy_->scene);
			player->Update(keys);
			player->enemy_->Update();
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
			if (player->GetTmpScene() == stage_3) {
				player->clearSave(isClear[2]);
			}
			if (player->GetTmpScene() == stage_4) {
				player->clearSave(isClear[3]);
			}
			if (player->GetTmpScene() == stage_5) {
				player->clearSave(isClear[4]);
			}
			if (player->GetTmpScene() == stage_6) {
				player->clearSave(isClear[5]);
			}
			if (player->GetTmpScene() == stage_7) {
				player->clearSave(isClear[6]);
			}
			if (player->GetTmpScene() == stage_8) {
				player->clearSave(isClear[7]);
			}
			if (player->GetTmpScene() == stage_9) {
				player->clearSave(isClear[8]);
			}
			if (player->GetTmpScene() == stage_10) {
				player->clearSave(isClear[9]);
			}
			if (player->GetTmpScene() == stage_11) {
				player->clearSave(isClear[10]);
			}
			if (player->GetTmpScene() == stage_12) {
				player->clearSave(isClear[11]);
			}
			if (player->GetTmpScene() == stage_13) {
				player->clearSave(isClear[12]);
			}
			if (player->GetTmpScene() == stage_14) {
				player->clearSave(isClear[13]);
			}
			if (player->GetTmpScene() == stage_15) {
				player->clearSave(isClear[14]);
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
			SpriteDraw(Vector2(0.0f, 0.0f), titelGH, WHITE);
			DrawButton(continueButton, continueGH, WHITE);
			DrawButton(AllResetButton, AllResetGH, WHITE);
			DrawButton(RuleButton, RuleButtonGH, WHITE);
			break;
		case rule:
			SpriteDraw(Vector2(0.0f, 0.0f), RuleGH, WHITE);
			DrawButton(XButton, XGH, WHITE);
			break;
		case Select:
			SpriteDraw(Vector2(0.0f, 0.0f), player->map->GetBackGroundGH(), WHITE);
			DrawButton(Stage_1st, number1GH);
			DrawButton(Stage_2nd, number2GH);
			DrawButton(Stage_3rd, number3GH);
			DrawButton(Stage_4th, number4GH);
			DrawButton(Stage_5th, number5GH);
			DrawButton(Stage_6th, number6GH);
			DrawButton(Stage_7th, number7GH);
			DrawButton(Stage_8th, number8GH);
			DrawButton(Stage_9th, number9GH);
			DrawButton(Stage_10th, number10GH);
			DrawButton(Stage_11th, number11GH);
			DrawButton(Stage_12th, number12GH);
			DrawButton(Stage_13th, number13GH);
			DrawButton(Stage_14th, number14GH);
			DrawButton(Stage_15th, number15GH);

			for (int i = 0; i < 15; i++) {
				if (isClear[i] == true) {
					DrawButton(ClearBotton[i], clearGH);

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
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_4:
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_5:
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_6:
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_7:
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_8:
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_9:
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_10:
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_11:
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_12:
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_13:
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_14:
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case stage_15:
			player->map->Draw(player->GetIsSave());
			player->Draw();
			player->enemy_->Draw();
			break;
		case gameClear:
			SpriteDraw(Vector2{ 0,0 }, GameClearGH, WHITE);
			DrawButton(titelButton, titelButtonGH, WHITE);
			break;
		case gameOver:
			SpriteDraw(Vector2{ 0,0 }, GameOverGH, WHITE);
			DrawButton(titelButton, WhiteGH_, BLACK);
			break;

		}
		SpriteDraw(Vector2{ (mouse.x - 16.0f),(mouse.y - 16.0f) }, mouseGH, WHITE);




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
