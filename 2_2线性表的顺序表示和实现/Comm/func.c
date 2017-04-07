#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "func.h"

Status InitList_Sq(pSqList L)
{
	//����һ���յ����Ա�
	Status Result = Error;
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)	//����洢�ռ�ʧ��
		exit(OverFlow);
	L->length = 0;	//��ʼ���ձ���Ϊ 0
	L->listsize = LIST_INIT_SIZE;	//��ʼ��һ���洢�ռ��С
	Result = OK;
	return Result;
}

void UnInitList_Sq(pSqList L)
{
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
	L->listsize = 0;
}

void ListClear(pSqList L)
{
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
}

Status ListInsert_Sq(pSqList L, int i, ElemType e)
{
	//��ѭ�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e��i�ĺϷ�ֵΪ 1 <= i <= ListLength_Sq(L) + 1
	Status Result = Error;
	if ((i < 1) || (i > L->length + 1))	//iֵ���Ϸ�
		return Error;
	if (L->length >= L->listsize)	//����洢�ռ����˾ʹ������ӷ���
	{
		ElemType *newbase = (ElemType *)realloc(L->elem, (L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if (!newbase)	//�洢����ʧ��
			exit(OverFlow);
		L->elem = newbase;	//�»�ַ
		L->listsize += LISTINCREMENT;	//���ӵĴ洢����
	}
	ElemType *q = &(L->elem[i - 1]);	//qΪ�����λ��
	ElemType *p;
	for (p = &(L->elem[L->length - 1]); p >= q; --p)	//����λ�ü�֮���Ԫ������
	{
		*(p + 1) = *p;
	}
	*q = e;	//���봫��� e ����
	++L->length;	//������ 1
	Result = OK;
	return Result;
}

Status ListDelete_Sq(pSqList L, int i, ElemType *e)
{
	//��˳�����Ա�L��ɾ����i��Ԫ�أ����� e ������ֵ
	//i �ĺϷ�ֵΪ 1 <= i <= ListLength_Sq(L)
	Status Result = Error;
	if ((i < 1) || (i > L->length))	// i ֵ���Ϸ�
	{
		return Error;
	}
	ElemType *p = &(L->elem[i - 1]);	//pΪ��ɾ��Ԫ�ص�λ��
	*e = *p;	//��ɾ��Ԫ�ص�ֵ���� e
	ElemType *q = L->elem + L->length - 1;	//��βԪ�ص�λ��
	for (++p; p <= q; ++p)
	{
		*(p - 1) = *p;	//��ɾ��Ԫ��֮���Ԫ������
	}
	--L->length;	//���� 1
	Result = OK;
	return Result;
}

int LocateElem_Sq(pSqList L, ElemType E)
{
	//��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ�����ҵ����򷵻�����L�е�λ�򣬷��򷵻�0
	int I = 1;	//i�ĳ�ֵΪ��1��Ԫ�ص�λ��
	ElemType *P = L->elem;	//p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
	while (I <= L->length)
	{
		if (Compare(*P, E))
		{
			break;
		}
		else
		{
			++P;
		}
		++I;
	}
	if (I <= L->length)
	{
		return I;
	}
	else
	{
		return 0;
	}
}

Status Compare(ElemType E1, ElemType E2)
{
	return E1 == E2 ? 1 : 0;
}

void ShowList(char *str, pSqList L, bool IsChar)
{
	int i;
	ElemType V;

	printf(str);
	printf("( ");

	for (i = 0; i < L->length; i++)
	{
		V = L->elem[i];
		IsChar ? printf("%d ", V) : printf("%c ", V);
	}

	printf(")\n");
}
