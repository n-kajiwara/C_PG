#include "Graphics.h"
#include "DxLib.h"

void RenderGraphics(const VECTOR2* leftTop, const unsigned int* graphics) {
	DrawGraph((int)leftTop->x, (int)leftTop->y, *graphics, TRUE);
}

void DrawString(char* str) {
	DrawString(20, 20, str, GetColor(255, 255, 255));
}

char* Convert(const int* src) {
	return NULL;
}