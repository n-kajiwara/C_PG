#include "Board.h"
#include "Graphics.h"
#include "DxLib.h"

int boardParam[BoardHeight][BoardWidth];
unsigned int boardGraph;
int mark[2];

void InitBoard() {
	boardGraph = LoadGraph("Board.png");
	mark[0] = LoadGraph("Maru.png");
	mark[1] = LoadGraph("Batsu.png");
	ResetParam();
}

void ResetParam() {
	ZeroMemory(boardParam, sizeof(boardParam));
	int idx = 0;
	for (idx = 0; idx < BoardWidth; idx++) {
		boardParam[0][idx] = Dammy;
		boardParam[BoardHeight - 1][idx] = Dammy;
	}
	for (idx = 1; idx < BoardWidth - 1; idx++) {
		boardParam[idx][0] = Dammy;
		boardParam[idx][BoardWidth - 1] = Dammy;
	}

}

void RenderBoard() {
	int row, col;
	VECTOR2 leftTop, size, cur;
	int sizeX, sizeY;
	unsigned int graph;
	GetGraphSize(boardGraph, &sizeX, &sizeY);
	leftTop.x = DrawBoardOffsetX;
	leftTop.y = DrawBoardOffsetY;
	size.x = (float)sizeX;
	size.y = (float)sizeY;
	RenderGraphics(&leftTop, &boardGraph);
	for (row = 0; row < BoardHeight; row++) {
		leftTop.y = DrawBoardOffsetY + (row - 1) * sizeY / FIELDHEIGHT;
		for (col = 0; col < BoardWidth; col++) {
			leftTop.x = DrawBoardOffsetX + (col - 1) * sizeX / FIELDWIDTH;
			cur.x = (float)col;
			cur.y = (float)row;
			graph = SetGraph(&cur);
			if (graph != GetColor(0, 0, 0)) {
				RenderGraphics(&leftTop, &graph);
			}
		}
	}
}

int SetGraph(const VECTOR2* cur) {
	int graph;
	switch (boardParam[(int)cur->y][(int)cur->x])
	{
	case P1_MK:
		graph = mark[0];
		break;
	case P2_MK:
		graph = mark[1];
		break;
	default:
		graph = GetColor(0, 0, 0);
		break;
	}
	return graph;
}

int Put(const VECTOR2* cur, const int* mark) {
	if (IsPut(cur) == NG) { return NG; }
	boardParam[(int)cur->y][(int)cur->x] = *mark;
	return OK;
}

int IsPut(const VECTOR2* cur) {
	int ret = NG;
	if (boardParam[(int)cur->y][(int)cur->x] == NONE) {
		ret = OK;
	}
	return ret;
}

int GetCell(const VECTOR2* cur) {
	return boardParam[(int)cur->y][(int)cur->x];
}


