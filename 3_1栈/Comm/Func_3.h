#include <strings.h>
#include "..\..\Comm\CommDef.h"

#define STACK_INIT_SIZE 100 //�洢�ռ��ʼ������ 
#define STACKINCREMENT 10	//�洢�ռ��������

typedef struct 
{
	SElemType *base;	//��ջ����֮ǰ������֮��base��ֵΪNULL
	SElemType *top;	//ջ��ָ��
	int stacksize;	//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
} SqStack;
