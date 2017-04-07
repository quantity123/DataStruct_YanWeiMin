#include <stdlib.h>
#include "Stack.h"

Status CreateStack(SqStack **S)
{
	*S = malloc(sizeof(SqStack));
	if (!*S)
		exit(OverFlow);	//内存分配失败
	memset(*S, 0, sizeof(SqStack));
	return OK;
}

Status DestroyStack(SqStack **S)
{
	free(*S);
	*S = NULL;
}

Status InitStack(SqStack *S)
{
	//构造一个空栈 S
	S->base = (MoveMazeElemType *)malloc(STACK_INIT_SIZE * sizeof(MoveMazeElemType));
	if (!S->base)
		exit(OverFlow);	//内存分配失败 
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

void ClearStack(SqStack *S)
{
	if (S->base)
		free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
}

Status Push(SqStack *S, MoveMazeElemType e)
{
	//插入元素 e 为新的栈顶元素
	int UsedSize;
	
	UsedSize = S->top - S->base;
	if (UsedSize >= S->stacksize)
	{
		//栈满，追加存储空间
		S->base = (MoveMazeElemType *)realloc(S->base, (S->stacksize+STACKINCREMENT) * sizeof(MoveMazeElemType));
		if (!S->base)
			exit(OverFlow);	//存储分配失败
		//S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Status Pop(SqStack *S, MoveMazeElemType *e)
{
	//若栈不空，则删除 S 的栈顶元素,用 e 返回其值，并返回 OK;否则返回Error
	if (S->top == S->base)
		return Error;
	*e = *--S->top;
	return OK;
}

Status GetTop(SqStack *S, MoveMazeElemType *e)
{
	//若栈不空，则用 e 返回 S 的栈顶元素，并返回OK,否则返回Error。
	if (S->top == S->base)
		return Error;
	*e = *(S->top-1);
	return OK;
}

Status StackEmpty(SqStack *S)
{
	if (S->base == S->top)
		return OK;
	else
		return Error;
}
