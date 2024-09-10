#include "Map.h"

Map::Map() {
}

void Map::Update() {
	for (int i = 0; i < MapY_; i++) {
		pMap[i] = map[i];
	}
	ppMap = pMap;

}

void Map::Draw() {
	for (int y = 0; y < MapY_; y++) {
		for (int x = 0; x < MapX_; x++) {
			if (map[y][x] == 1) {
				Novice::DrawSprite(
					blockSize * x , blockSize * y,
					blockGH,
					1.0f, 1.0f,
					0.0f, 0xFFFFFFFF);
			}
			if (map[y][x] == 3){
				Novice::DrawSprite(
					blockSize * x, blockSize * y,
					saveGH,
					0.5, 0.5f,
					0.0f, 0xFFFFFFFF);
			}
		}
	}

}

Vector2 Map::GetMapPos(int mapNumber){
	Vector2 pos;
	for (int y = 0; y < MapY_; y++){
		for (int x = 0; x < MapX_; x++){
			if (map[y][x]== mapNumber){
				pos.x = static_cast<float>(blockSize * x);
				pos.y = static_cast<float>(blockSize * y);
			}
		}
	}
	return pos;
}


