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
		}
	}

}
