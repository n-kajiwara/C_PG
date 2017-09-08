#pragma once
#include "GameParam.h"

void InitPlayer();
void UpdatePlayer();
void RenderPlayer();
void ChangeTurn();
int DecideCheck(const VECTOR2* cursorPos);
int CheckAlign(const VECTOR2* cur, const int* piece);
int CheckLine(const VECTOR2* cur, const int* piece, const VECTOR2* dir);
int IsEnd();