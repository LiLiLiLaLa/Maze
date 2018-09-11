#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

#define START_SIZE 3//栈起始默认大小
#define ADD_SIZE 2//增长因子

typedef struct Pos
{
	int _row;//行
	int _col;//列
}Pos;//用结构体定义坐标位置

typedef Pos DataType;

typedef struct Stack
{
	DataType* _a;//指向坐标结构体的指针
	int _top;//栈中已有元素个数
	int _capacity;//容量
}Stack;//定义栈，存放坐标

void StackInit(Stack* ps);//初始化栈
void StackDestory(Stack* ps);//销毁栈
void StackPush(Stack* ps, DataType x);//元素入栈
void StackPop(Stack* ps);//弹栈
DataType StackTop(const Stack* ps);//返回栈顶元素
int StackEmpty(const Stack* ps);//判空
int StackSize(const Stack* ps);//计算栈中元素多少

void TestStack();

#endif//__STACK_H__