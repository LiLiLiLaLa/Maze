#include "Maze.h"

void MazePrint()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}//打印迷宫

int CheckAccess(Pos next)
{
	if ((next._col >= 0) && (next._row >= 0) 
		&& (next._col < N) && (next._row < N))//判断是否越界
	{
		if (maze[next._row][next._col] == 1)//下一步是才是通路
		{
			return 1;//1表示可以通过
		}
	}
	return 0;//无法通过返回0
}//判断下一步是否可通过

int MazeCheckIsAccess(Pos cur, Pos next)
{
	//判断越界的情况
	if ((next._col >= 0 && next._row >= 0
		&& next._col < N && next._row<N)
		&& (maze[next._row][next._col] == 1
		|| maze[next._row][next._col]>maze[cur._row][cur._col] + 1))
	{
		return 1;
	}
	//return 0表示不可以通过
	return 0;
}//寻找最短路径探测下一步是否可通过

int pathsize = 0;

int MazeGetPath(Pos entry)
{
	Pos cur = entry;//记录迷宫入口
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);//将入口坐标压栈
	maze[entry._row][entry._col] = 2;//走过的地方置为2
	while (StackEmpty(&path))//栈不为空时继续走
	{
		cur = StackTop(&path);
		maze[cur._row][cur._col] = 2;//走过的地方置为2
		if (cur._col == 5)//走到出口
		{
			if ((pathsize == 0) || StackSize(&path)<pathsize)//已经找到出口还可以往上下走时
			{
				pathsize = StackSize(&path);//路径为第一次走到出口为准
			}
		}
		//下
		Pos next = cur;
		next._row -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//上11
		next = cur;
		next._row += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//左
		next = cur;
		next._col -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//右
		next = cur;
		next._col += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		StackPop(&path);//回溯
	}
	return 0;
}//获取一条走出迷宫的路径

int MazeGetShortPath(Pos entry)
{
	Pos cur = entry;//记录迷宫入口
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);//将入口坐标压栈
	maze[entry._row][entry._col] = 2;//走过的地方置为2
	while (StackEmpty(&path))
	{
		cur = StackTop(&path);
		if (cur._col == 5)
		{
			if ((pathsize == 0) || StackSize(&path) < pathsize)//已经找到出口还可以往上下走时
			{
				pathsize = StackSize(&path);//路径为第一次走到出口为准
			}
		}
		//下
		Pos next = cur;
		next._row -= 1;
		if (MazeCheckIsAccess(cur,next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//上
		next = cur;
		next._row += 1;
		if (MazeCheckIsAccess(cur,next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//左
		next = cur;
		next._col -= 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//右
		next = cur;
		next._col += 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		//回溯
		StackPop(&path);
	}
	return 0;
}//找寻最短路径

void TestMaze()
{
	Pos entry;
	entry._row = 5;
	entry._col = 2;
	/*Pos exit;
	exit._row = 4;
	exit._col = 5;*/
	MazePrint();
	//printf("是否有出口？%d\n",MazeGetPath(entry,exit));
	MazeGetShortPath(entry);
	printf("最短路径：%d\n", pathsize);
	MazePrint();
}
