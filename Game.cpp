#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "DxLib.h"
#include "Input.h"
#include <string.h>
#include <stdio.h>

char winStr[10];
int gameParam;

void InitGame() {
	InitBoard();
	InitPlayer();
	strcpy(winStr, "");
	gameParam = 0;
}

void ResetGame() {
	ResetParam();
	InitPlayer();
	strcpy(winStr, "");
	gameParam = -1;
}

void UpdateGame() {
	int padNo = DX_INPUT_KEY_PAD1;
	UpdateKeyboardState(&padNo);
	gameParam = IsEnd();
	if (gameParam < 0) {
		UpdatePlayer();
		switch (IsEnd())
		{
		case P1_MK:
			gameParam = P1_MK;
			break;
		case P2_MK:
			gameParam = P2_MK;
			break;
		case 0:
			gameParam = 0;
			break;
		}
		if (gameParam >= 0) {
			sprintf(winStr, "%d", gameParam);
		}
	}
	else {
		if (IsKeyDown(PAD_INPUT_10)) {
			InitGame();
		}
	}
}

void RenderGame() {
	RenderBoard();
	if (strcmp(winStr, "") == 0) {
		RenderPlayer();
	}
	else {
		char str[20];
		if (gameParam > 0) {
			strcpy(str, "WIN:PLAYER");
			strcat(str, winStr);
		}
		else {
			strcpy(str, "DRAW");
		}
		DrawString(20, 40, str, GetColor(255, 255, 255));
	}
}