#include <stdlib.h>
#include "Stack.h"

Status CreateStack(SqStack **S)
{
	*S = malloc(sizeof(SqStack));
	if (!*S)
		exit(OverFlow);	//�ڴ����ʧ��
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
	//����һ����ջ S
	S->base = (MoveMazeElemType *)malloc(STACK_INIT_SIZE * sizeof(MoveMazeElemType));
	if (!S->base)
		exit(OverFlow);	//�ڴ����ʧ�� 
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
	//����Ԫ�� e Ϊ�µ�ջ��Ԫ��
	int UsedSize;
	
	UsedSize = S->top - S->base;
	if (UsedSize >= S->stacksize)
	{
		//ջ����׷�Ӵ洢�ռ�
		S->base = (MoveMazeElemType *)realloc(S->base, (S->stacksize+STACKINCREMENT) * sizeof(MoveMazeElemType));
		if (!S->base)
			exit(OverFlow);	//�洢����ʧ��
		//S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Status Pop(SqStack *S, MoveMazeElemType *e)
{
	//��ջ���գ���ɾ�� S ��ջ��Ԫ��,�� e ������ֵ�������� OK;���򷵻�Error
	if (S->top == S->base)
		return Error;
	*e = *--S->top;
	return OK;
}

Status GetTop(SqStack *S, MoveMazeElemType *e)
{
	//��ջ���գ����� e ���� S ��ջ��Ԫ�أ�������OK,���򷵻�Error��
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
