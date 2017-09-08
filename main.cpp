#include "DxLib.h"
#include "main.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//DXライブラリ初期化
	if (DxLib_Init() == -1){ return -1; }

	ChangeWindowMode(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
	InitGame();
	// 描画先画面を裏画面にセット

	//ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		Update();
		Render();
	}

	DxLib_End();

	return 0; 
}

void Init() {
	InitGame();
}

void Update() {
	UpdateGame();
}

void Render() {
	ClearDrawScreen();// 画面を初期化する
	RenderGame();
	ScreenFlip();		// 裏画面の内容を表画面に反映させる
}