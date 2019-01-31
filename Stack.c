#include "Stack.h"


void StackInit(Stack* ps)
{
	ps->_a = (DataType*)malloc(sizeof(DataType)*START_SIZE);
	ps->_top = 0;
	ps->_capacity = START_SIZE;
}//初始化栈

void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_a == NULL)
	{
		return;
	}
	else
	{
		free(ps->_a);
		ps->_a = NULL;
	}
}//销毁栈

void StackPush(Stack* ps, DataType x)
{
	assert(ps);
	//若需要扩容
	if (ps->_capacity == ps->_top)//栈已满,需要扩容
	{
		ps->_a = realloc(ps->_a, sizeof(DataType)*(ps->_capacity + ADD_SIZE));//realloc两个从参数：指向要扩容的空间的指针、扩容后空间大小
		ps->_capacity += ADD_SIZE;
		if (ps->_a == NULL)//当malloc扩容失败时返回空
		{
			perror("增容出错");
			return;
		}
	}
	//无需增容或已经增容成功
	ps->_a[ps->_top] = x;//元素入栈
	ps->_top++;//元素入栈，已有元素个数增加
}//元素入栈

void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return;//空栈，无法弹栈
	}
	ps->_top--;//top--,访问不到原本栈顶元素，相当于弹栈
}//元素出栈

DataType StackTop(const Stack* ps)
{
	Pos s;
	s._col = -1;
	s._row = -1;
	assert(ps);
	if (ps->_top == 0)
	{
		return s;//空栈无法返回栈顶，函数要求返回值类型是DataType，所以定义一个非法坐标作为返回值
	}
	else
	{
		return ps->_a[ps->_top - 1];
	}
}//返回栈顶元素

int StackEmpty(const Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;//空栈返回0非空返回1
}//判空

int StackSize(const Stack* ps)
{
	assert(ps);
	return ps->_top;
}//计算栈中元素多少
