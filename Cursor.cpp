#include "Cursor.h"
#include "Input.h"
#include "Board.h"
#include "DxLib.h"
#include "Graphics.h"

VECTOR2 cursorPos;
unsigned int cursorGraph;

void InitCursor() {
	cursorGraph = LoadGraph("Cursor.png");
	ResetCurosrPosition();
}

void UpdateCursor() {
	MoveCursor();
}

void RenderCursor() {
	VECTOR2 leftTop, rightBottom;
	leftTop.x = DrawBoardOffsetX + (cursorPos.x - 1) * 32;
	leftTop.y = DrawBoardOffsetY + (cursorPos.y - 1) * 32;
	RenderGraphics(&leftTop, &cursorGraph);
}

void MoveCursor() {
	int dirX = 0;
	int dirY = 0;
	VECTOR2 next = {0, 0};
	//�E�L�[����
	if (IsKeyDown(PAD_INPUT_RIGHT)) {
		next.y = cursorPos.y;
		next.x = cursorPos.x + 1;
		if (GetCell(&next) != Dammy) {	//�֐��o�R�ŃZ�����e�擾
			dirX = 1;
		}
	}
	//���L�[����
	else if (IsKeyDown(PAD_INPUT_LEFT)) {
		next.y = cursorPos.y;
		next.x = cursorPos.x - 1;
		if (GetCell(&next) != Dammy) {	//�֐��o�R�ŃZ�����e�擾
			dirX = -1;
		}
	}
	//��L�[����
	else if (IsKeyDown(PAD_INPUT_UP)) {
		next.y = cursorPos.y - 1;
		next.x = cursorPos.x;
		if (GetCell(&next) != Dammy) {	//�֐��o�R�ŃZ�����e�擾
			dirY = -1;
		}
	}
	//���L�[����
	else if (IsKeyDown(PAD_INPUT_DOWN)) {
		next.y = cursorPos.y + 1;
		next.x = cursorPos.x;
		if (GetCell(&next) != Dammy) {	//�֐��o�R�ŃZ�����e�擾
			dirY = 1;
		}
	}
	cursorPos.x += dirX;
	cursorPos.y += dirY;
}

void ResetCurosrPosition() {
	cursorPos.x = (float)(BoardWidth / 2);
	cursorPos.y = (float)(BoardHeight / 2);
}

VECTOR2 GetCursorPosition() {
	return cursorPos;
}