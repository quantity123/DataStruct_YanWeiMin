#include "..\..\Comm\CommDef.h"

//˳���ͷ�ṹ�����Ͷ���
typedef struct
{
	ElemType *elem;	//�洢�ռ��ַ
	int length;	//��ǰ����
	int listsize;	//��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
} SqList, *pSqList;
