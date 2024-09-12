#include"Scene.h"
#include "Novice.h"

void DrawButton(Button button, int Gh){
	Novice::DrawQuad(
		int(button.pos.x - button.size.x * 0.5f),
		int(button.pos.y - button.size.y * 0.5f),
		int(button.pos.x + button.size.x * 0.5f),
		int(button.pos.y - button.size.y * 0.5f),
		int(button.pos.x - button.size.x * 0.5f),
		int(button.pos.y + button.size.y * 0.5f),
		int(button.pos.x + button.size.x * 0.5f),
		int(button.pos.y + button.size.y * 0.5f),
		0, 0,
		int(button.size.x), int(button.size.y),
		Gh,
		WHITE
	);
}

void DrawButton(Button button, int Gh, int color){
	Novice::DrawQuad(
		int(button.pos.x - button.size.x * 0.5f),
		int(button.pos.y - button.size.y * 0.5f),
		int(button.pos.x + button.size.x * 0.5f),
		int(button.pos.y - button.size.y * 0.5f),
		int(button.pos.x - button.size.x * 0.5f),
		int(button.pos.y + button.size.y * 0.5f),
		int(button.pos.x + button.size.x * 0.5f),
		int(button.pos.y + button.size.y * 0.5f),
		0, 0,
		int(button.size.x), int(button.size.y),
		Gh,
		color
	);
}
