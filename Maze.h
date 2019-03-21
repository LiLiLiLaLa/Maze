#pragma once


#include "Stack.h"
#define N 6

//迷宫的定义
static int maze[N][N] = {
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 },
};



void MazePrint();
int MazeGetPath(Pos entry);
int MazeCheckIsAccess(Pos cur, Pos next);
int MazeGetShortPath(Pos entry);
int CheckAccess(Pos next);
void TestMaze();

