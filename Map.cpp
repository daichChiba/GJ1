#include "Map.h"

Map::Map() {
	ppMap = (int**)malloc(MAX_HEIGHT * sizeof(int*));
	for (int i = 0; i < MAX_HEIGHT; i++) {
		ppMap[i] = (int*)malloc(MAX_WIDTH * sizeof(int));
	}
}

void Map::Update(Scene_ scene) {
	if (scene==stage_1){
		loadMapChip_->MapChipLood(ppMap, "./Resource/Csv/stage_1.csv");
	}
	if (scene==stage_2){
		loadMapChip_->MapChipLood(ppMap, "./Resource/Csv/stage_2.csv");
	}


}

void Map::Draw() {
	Novice::DrawSprite(0, 0, backGroundGH, 1.0f, 1.0f, 0.0f, WHITE);
	for (int y = 0; y < MapY_; y++) {
		for (int x = 0; x < MapX_; x++) {
			if (ppMap[y][x] == 1) {
				Novice::DrawSprite(
					blockSize * x , blockSize * y,
					blockGH,
					1.0f, 1.0f,
					0.0f, 0xFFFFFFFF);
			}
			if (ppMap[y][x] == 3) {
				Novice::DrawSprite(
					blockSize * x, blockSize * y,
					noSaveGH,
					0.5, 0.5f,
					0.0f, 0xFFFFFFFF);
			}
			if (ppMap[y][x] == 4) {
				Novice::DrawSprite(
					blockSize * x, blockSize * y,
					GoalGH,
					1.0f, 1.0f,
					0.0f, 0xFFFFFFFF);
			}

		}
	}

}

void Map::ResetMap(int**& map){
	// 既存のマップのメモリを解放
	for (int i = 0; i < MAX_HEIGHT; i++) {
		free(map[i]);
	}
	free(map);

	// 新しいマップ用にメモリを再確保
	map = (int**)malloc(MAX_HEIGHT * sizeof(int*));
	for (int i = 0; i < MAX_HEIGHT; i++) {
		map[i] = (int*)malloc(MAX_WIDTH * sizeof(int));
	}
}

Vector2 Map::GetMapPos(int mapNumber){
	Vector2 pos;
	for (int y = 0; y < MapY_; y++){
		for (int x = 0; x < MapX_; x++){
			if (ppMap[y][x]== mapNumber){
				pos.x = static_cast<float>(blockSize * x);
				pos.y = static_cast<float>(blockSize * y);
			}
		}
	}
	return pos;
}




