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
}//��ӡ�Թ�

int CheckAccess(Pos next)
{
	if ((next._col >= 0) && (next._row >= 0) 
		&& (next._col < N) && (next._row < N))//�ж��Ƿ�Խ��
	{
		if (maze[next._row][next._col] == 1)//��һ���ǲ���ͨ·
		{
			return 1;//1��ʾ����ͨ��
		}
	}
	return 0;//�޷�ͨ������0
}//�ж���һ���Ƿ��ͨ��

int MazeCheckIsAccess(Pos cur, Pos next)
{
	//�ж�Խ������
	if ((next._col >= 0 && next._row >= 0
		&& next._col < N && next._row<N)
		&& (maze[next._row][next._col] == 1
		|| maze[next._row][next._col]>maze[cur._row][cur._col] + 1))
	{
		return 1;
	}
	//return 0��ʾ������ͨ��
	return 0;
}//Ѱ�����·��̽����һ���Ƿ��ͨ��

int pathsize = 0;

int MazeGetPath(Pos entry)
{
	Pos cur = entry;//��¼�Թ����
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);//���������ѹջ
	maze[entry._row][entry._col] = 2;//�߹��ĵط���Ϊ2
	while (StackEmpty(&path))//ջ��Ϊ��ʱ������
	{
		cur = StackTop(&path);
		maze[cur._row][cur._col] = 2;//�߹��ĵط���Ϊ2
		if (cur._col == 5)//�ߵ�����
		{
			if ((pathsize == 0) || StackSize(&path)<pathsize)//�Ѿ��ҵ����ڻ�������������ʱ
			{
				pathsize = StackSize(&path);//·��Ϊ��һ���ߵ�����Ϊ׼
			}
		}
		//��
		Pos next = cur;
		next._row -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//��11
		next = cur;
		next._row += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._col -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._col += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		StackPop(&path);//����
	}
	return 0;
}//��ȡһ���߳��Թ���·��

int MazeGetShortPath(Pos entry)
{
	Pos cur = entry;//��¼�Թ����
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);//���������ѹջ
	maze[entry._row][entry._col] = 2;//�߹��ĵط���Ϊ2
	while (StackEmpty(&path))
	{
		cur = StackTop(&path);
		if (cur._col == 5)
		{
			if ((pathsize == 0) || StackSize(&path) < pathsize)//�Ѿ��ҵ����ڻ�������������ʱ
			{
				pathsize = StackSize(&path);//·��Ϊ��һ���ߵ�����Ϊ׼
			}
		}
		//��
		Pos next = cur;
		next._row -= 1;
		if (MazeCheckIsAccess(cur,next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._row += 1;
		if (MazeCheckIsAccess(cur,next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._col -= 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//��
		next = cur;
		next._col += 1;
		if (MazeCheckIsAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		//����
		StackPop(&path);
	}
	return 0;
}//��Ѱ���·��

void TestMaze()
{
	Pos entry;
	entry._row = 5;
	entry._col = 2;
	/*Pos exit;
	exit._row = 4;
	exit._col = 5;*/
	MazePrint();
	//printf("�Ƿ��г��ڣ�%d\n",MazeGetPath(entry,exit));
	MazeGetShortPath(entry);
	printf("���·����%d\n", pathsize);
	MazePrint();
}
