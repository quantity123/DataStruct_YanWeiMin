#include <strings.h>
#include "..\..\Comm\CommDef.h"

#define STACK_INIT_SIZE 100 //�洢�ռ��ʼ������ 
#define STACKINCREMENT 10	//�洢�ռ��������

typedef struct
{
	_Bool Forward, Down, Backward, Up;
} Way;

typedef struct
{
	short i;	//ͨ�������Թ��е�����λ��X,Y
	short j;	
	Way w;	//�Ӵ�ͨ����������һͨ����ķ���
} MoveMazeElemType;

typedef struct 
{
	MoveMazeElemType *base;	//��ջ����֮ǰ������֮��base��ֵΪNULL
	MoveMazeElemType *top;	//ջ��ָ��
	int stacksize;	//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ 
} SqStack;


