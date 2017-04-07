#include <stdlib.h>
#include "SqQueue.h"

int InitSqQueue(SqQueue *Q)
{
	//构造一个空队列
	Q->base = malloc(MAXQSIZE * sizeof(int));
	if (!Q->base)
		exit(-1);	//存储分配失败
	Q->front = Q->rear = 0;
	return 0; 
}

int SqQueueLength(SqQueue *Q)
{
	//返回 Q 的元素个数，即队列的长度 
	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
}

int EnQueue(SqQueue *Q, int e)
{
	//插入元素 e 为 Q 的新的队尾元素
	if ((Q->rear + 1) % MAXQSIZE == Q->front)	//队列满 
		return -1;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return 0;
}

int DeQueue(SqQueue *Q, int *e)
{
	//若队列不空，则删除 Q 的队头元素，用 e 返回其值，并返回 0
	//否则返回 -1
	if (Q->front == Q->rear)
		return -1;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return 0;
}


