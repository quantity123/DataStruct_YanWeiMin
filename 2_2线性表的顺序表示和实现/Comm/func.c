#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "func.h"

Status InitList_Sq(pSqList L)
{
	//构造一个空的线性表
	Status Result = Error;
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)	//分配存储空间失败
		exit(OverFlow);
	L->length = 0;	//初始化空表长度为 0
	L->listsize = LIST_INIT_SIZE;	//初始化一个存储空间大小
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
	//在循序线性表L中第i个位置之前插入新的元素e，i的合法值为 1 <= i <= ListLength_Sq(L) + 1
	Status Result = Error;
	if ((i < 1) || (i > L->length + 1))	//i值不合法
		return Error;
	if (L->length >= L->listsize)	//如果存储空间满了就从新增加分配
	{
		ElemType *newbase = (ElemType *)realloc(L->elem, (L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if (!newbase)	//存储分配失败
			exit(OverFlow);
		L->elem = newbase;	//新基址
		L->listsize += LISTINCREMENT;	//增加的存储容量
	}
	ElemType *q = &(L->elem[i - 1]);	//q为插入的位置
	ElemType *p;
	for (p = &(L->elem[L->length - 1]); p >= q; --p)	//插入位置及之后的元素右移
	{
		*(p + 1) = *p;
	}
	*q = e;	//插入传入的 e 数据
	++L->length;	//表增长 1
	Result = OK;
	return Result;
}

Status ListDelete_Sq(pSqList L, int i, ElemType *e)
{
	//在顺序线性表L中删除第i个元素，并用 e 返回其值
	//i 的合法值为 1 <= i <= ListLength_Sq(L)
	Status Result = Error;
	if ((i < 1) || (i > L->length))	// i 值不合法
	{
		return Error;
	}
	ElemType *p = &(L->elem[i - 1]);	//p为被删除元素的位置
	*e = *p;	//被删除元素的值传给 e
	ElemType *q = L->elem + L->length - 1;	//表尾元素的位置
	for (++p; p <= q; ++p)
	{
		*(p - 1) = *p;	//被删除元素之后的元素左移
	}
	--L->length;	//表长减 1
	Result = OK;
	return Result;
}

int LocateElem_Sq(pSqList L, ElemType E)
{
	//在顺序线性表L中查找第1个值与e满足compare()的元素的位序，若找到，则返回其在L中的位序，否则返回0
	int I = 1;	//i的初值为第1个元素的位序
	ElemType *P = L->elem;	//p的初值为第1个元素的存储位置
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
