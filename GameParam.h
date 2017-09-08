#pragma once
#define BoardWidth 5
#define BoardHeight 5
#define FIELDWIDTH (BoardWidth / 2 + 1)
#define FIELDHEIGHT (BoardHeight / 2 + 1)
#define DrawBoardOffsetX 100
#define DrawBoardOffsetY 100
#define Dammy 9
#define NONE 0
#define P1_MK 1
#define P2_MK 2
#define NG 0
#define OK 1
#define WIN_AROUND_NUM 2

typedef struct _VECTOR2 {
	float x;
	float y;
}VECTOR2;