#include <stdlib.h>
#include "SqQueue.h"

int InitSqQueue(SqQueue *Q)
{
	//����һ���ն���
	Q->base = malloc(MAXQSIZE * sizeof(int));
	if (!Q->base)
		exit(-1);	//�洢����ʧ��
	Q->front = Q->rear = 0;
	return 0; 
}

int SqQueueLength(SqQueue *Q)
{
	//���� Q ��Ԫ�ظ����������еĳ��� 
	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
}

int EnQueue(SqQueue *Q, int e)
{
	//����Ԫ�� e Ϊ Q ���µĶ�βԪ��
	if ((Q->rear + 1) % MAXQSIZE == Q->front)	//������ 
		return -1;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return 0;
}

int DeQueue(SqQueue *Q, int *e)
{
	//�����в��գ���ɾ�� Q �Ķ�ͷԪ�أ��� e ������ֵ�������� 0
	//���򷵻� -1
	if (Q->front == Q->rear)
		return -1;
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return 0;
}


