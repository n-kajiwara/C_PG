#include "Input.h"
#include "DxLib.h"

int curKeyState;
int prevKeyState;

void UpdateKeyboardState(const int* padNo) {
	prevKeyState = curKeyState;
	curKeyState = GetJoypadInputState(*padNo);
}

int IsKeyDown(const int key) {
	int cur = IsPressed(key);
	int prev = key & prevKeyState;
	return ((cur) && !(cur & prev));
}

int IsPressed(const int key) {
	return (key & curKeyState);
}