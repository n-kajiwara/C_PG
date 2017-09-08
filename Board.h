#pragma once
#include "GameParam.h"

void InitBoard();
void RenderBoard();
void ResetParam();
int SetGraph(const VECTOR2* cur);
int Put(const VECTOR2* cur, const int* mark);
int IsPut(const VECTOR2* cur);
int GetCell(const VECTOR2* cur);

extern int boardParam[BoardHeight][BoardWidth];