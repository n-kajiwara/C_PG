#define _CRT_SECURE_NO_WARNINGS
#include "Player.h"
#include "Board.h"
#include "DxLib.h"
#include "Input.h"
#include "Cursor.h"
#define DIRECTION_NUM 8

int players[2];
int cur_turn;
int win;
int turnCnt;

void InitPlayer() {
	cur_turn = 1;
	win = -1;
	int idx = 0;
	for (idx = 0; idx < 2; idx++) {
		players[idx] = idx + 1;
	}
	InitCursor();
	turnCnt = 1;
}

void UpdatePlayer() {
	VECTOR2 cursorPos;
	if (turnCnt > (FIELDWIDTH * FIELDHEIGHT)){
		win = 0;
		return;
	}
	UpdateCursor();
	cursorPos = GetCursorPosition();
	if (DecideCheck(&cursorPos) == NG) { return; }
	if (CheckAlign(&cursorPos, &players[cur_turn - 1]) == OK) {
		win = cur_turn;
	}
	else {
		turnCnt++;
		ChangeTurn();
		ResetCurosrPosition();
	}
}

void RenderPlayer() {
	char str[10] = "turn";
	char turnStr[10];
	sprintf(turnStr, "%d", players[cur_turn - 1]);
	str[4] += turnStr[0];
	RenderCursor();
	DrawString(20, 20, str, GetColor(255, 255, 255));
}

int DecideCheck(const VECTOR2* cursorPos) {
	if (!IsKeyDown(PAD_INPUT_4)) { return NG; }
	return (Put(cursorPos, &players[cur_turn - 1]) == OK);
}

void ChangeTurn() {
	cur_turn = (cur_turn % 2) + 1;
}

int CheckAlign(const VECTOR2* cur, const int* piece) {
	VECTOR2 dir[DIRECTION_NUM / 2] = {
		{ -1, 0 },	//上
		{ -1, -1 },	//左上
		{ 0, -1 },	//左
		{ -1, 1 },	//右上
	};
	int cnt = 0;
	int idx;
	for (idx = 0; idx < (DIRECTION_NUM / 2) && cnt < WIN_AROUND_NUM; idx++) {
		cnt = CheckLine(cur, piece, &dir[idx]);
		if (cnt <= 1) {
			//反対方向チェック
			dir[idx].x *= -1;
			dir[idx].y *= -1;
			cnt += CheckLine(cur, piece, &dir[idx]);
		}
	}
	return cnt == WIN_AROUND_NUM;
}

int CheckLine(const VECTOR2* cur, const int* piece, const VECTOR2* dir) {
	int cnt = 0;
	VECTOR2 next = { cur->x + dir->x, cur->y + dir->y };
	if (boardParam[(int)next.y][(int)next.x] != *piece) { return 0; } //externの配列使用
	cnt = 1;
	cnt += CheckLine(&next, piece, dir);
	return cnt;
}

int IsEnd() {
	return win;
}