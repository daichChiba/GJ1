#include"Scene.h"
#include "Novice.h"

void DrawButton(Button button, int Gh){
	Novice::DrawQuad(
		static_cast<int>(button.pos.x - button.size.x * 0.5f),
		static_cast<int>(button.pos.y - button.size.y * 0.5f),
		static_cast<int>(button.pos.x + button.size.x * 0.5f),
		static_cast<int>(button.pos.y - button.size.y * 0.5f),
		static_cast<int>(button.pos.x - button.size.x * 0.5f),
		static_cast<int>(button.pos.y + button.size.y * 0.5f),
		static_cast<int>(button.pos.x + button.size.x * 0.5f),
		static_cast<int>(button.pos.y + button.size.y * 0.5f),
		0, 0,
		static_cast<int>(button.size.x), static_cast<int>(button.size.y),
		Gh,
		WHITE
	);
}

void DrawButton(Button button, int Gh, int color){
	Novice::DrawQuad(
		static_cast<int>(button.pos.x - button.size.x * 0.5f),
		static_cast<int>(button.pos.y - button.size.y * 0.5f),
		static_cast<int>(button.pos.x + button.size.x * 0.5f),
		static_cast<int>(button.pos.y - button.size.y * 0.5f),
		static_cast<int>(button.pos.x - button.size.x * 0.5f),
		static_cast<int>(button.pos.y + button.size.y * 0.5f),
		static_cast<int>(button.pos.x + button.size.x * 0.5f),
		static_cast<int>(button.pos.y + button.size.y * 0.5f),
		0, 0,
		static_cast<int>(button.size.x), static_cast<int>(button.size.y),
		Gh,
		color
	);
}

void SpriteDraw(Vector2 pos, int Gh, int color){
	Novice::DrawSprite(
		static_cast<int>(pos.x), static_cast<int>(pos.y),
		Gh,
		1.0f, 1.0f,
		0.0f,
		color
	);
}
