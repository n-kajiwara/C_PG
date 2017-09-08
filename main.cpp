#include "DxLib.h"
#include "main.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//DX���C�u����������
	if (DxLib_Init() == -1){ return -1; }

	ChangeWindowMode(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
	InitGame();
	// �`����ʂ𗠉�ʂɃZ�b�g

	//�Q�[�����[�v
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
	ClearDrawScreen();// ��ʂ�����������
	RenderGame();
	ScreenFlip();		// ����ʂ̓��e��\��ʂɔ��f������
}