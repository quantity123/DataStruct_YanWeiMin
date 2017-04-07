#include <stdio.h>
#include <stdlib.h>
#include "func2_3.h"

/**************************LinkList动态单向链表*******************************/

void CreateList_L(LinkList L, int N, _Bool IsChar)
{
	//逆位序输入n个元素的值，建立带表头节点的单链线性表
	int i;

	for (i = N; i > 0; --i)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));	//生成新节点
		memset(p, 0, sizeof(LNode));
		if (IsChar)
			scanf("%c", &p->Data);	//输入元素值字符
		else
			scanf("%d", &p->Data);	//输入元素值数字
		fflush(stdin);
		p->Next = L->Next;
		L->Next = p;
	}
}

void Destroy_L(LinkList L)
{
	LinkList p;
	
	L = L->Next;
	while (L != NULL)
	{
		p = L->Next;
		free(L);
		p = p;
	}	
}

Status ListInsert_L(LinkList L, int i, ElemType e)
{
	//在带头结点的单链线性表L的第i个元素之前插入元素e
	LinkList p;
	int j = 0;
	Status Result = Error;

	while (L && j < i - 1)
	{
		//寻找第i-1个结点
		L = L->Next;
		++j;
	}
	if (!L || j > i-1)
		return Result;	//i小于1或者大于表长
	p = (LinkList)malloc(sizeof(LNode));	//生成新结点
	p->Data = e;
	p->Next = L->Next;	//插入L中
	L->Next = p;

	Result = OK;
	return Result;
}

Status ListDelete_L(LinkList L, int i, ElemType *e)
{
	//在带头节点的单链线性表L中，删除第i个元素，并由e返回其值
	Status Result = False;
	LinkList p, q;

	p = L;
	int j = 0;
	while (p->Next && j < i-1)	//寻找第i个结点，并令p指向其前趋
	{
		p = p->Next;
		++j;
	}
	if (!(p->Next) || j > i-1)
		return Error;

	q = p->Next;
	p->Next = q->Next;
	*e = q->Data;

	free(q);

	Result = OK;
	return Result;
}

Status GetElem_L(LinkList L, int i,  ElemType *e)
{
	//L为带头节点的单链表的头指针
	//当第i个元素存在时，其值赋给e并返回OK，否则返回Error
	LinkList p;

	Status Result = Error;

	p = L->Next;
	int j = 1;	//初始化，p指向第一个节点，j为计数器
	while (p && j<i)	//顺指针向后查找，直到p指向第i个元素或p为空
	{
		p = p->Next;
		++j;
	}
	if (!p || j>i)
		return Error;	//第i个元素不存在
	*e = p->Data;	//取第i个元素

	Result = OK;
	return Result;
}

void MergeList_L(LinkList La, LinkList Lb, LinkList Lc)
{
	//已知单链线性表La和Lb的元素按值非递减排列
	//并归La和Lb得到新的单链线性表Lc,Lc的元素也按值非递减排列
	//LinkList pa = La->Next;
	//LinkList pb = Lb->Next;
	La = La->Next;
	Lb = Lb->Next;

	while (La && Lb)
	{
		if (La->Data <= Lb->Data)
		{
			Lc->Next = La;
			La = La->Next;
		}
		else
		{
			Lc->Next = Lb;
			Lb = Lb->Next;
		}
		Lc = Lc->Next;
	}
	while (La)	//插入剩余La段
	{
		Lc->Next = La;
		La = La->Next;
		Lc = Lc->Next;
	}
	while (Lb)	//插入剩余Lb段
	{
		Lc->Next = Lb;
		Lb = Lb->Next;
		Lc = Lc->Next;
	}
}

void ShowList_L(char *s, LinkList L, _Bool IsChar)
{
	printf(s);
	printf("(");
	L = L->Next;
	while (L != NULL)
	{
		if (IsChar)
		{
			printf(" %c ", L->Data);
		}
		else
		{
			printf(" %d ", L->Data);
		}
		L = L->Next;
	}
	printf(")\n");
}

/**************************SLinkList静态单向链表*******************************/

void InitSpace_SL(SLinkList *SL)
{
	//将一维数组SL中各分量链成一个备用链表，SL为头指针
	//0 表示空指针
	int i;
	for (i = 0; i < MAXSIZE; ++i)
	{
		(*SL)[i].cur = i+1;
	}
	(*SL)[MAXSIZE].cur = 0;
}

Status SetData_SL(SLinkList *SL, int i, ElemType e)
{
	if ((i <= 0) || (i > MAXSIZE))
	{
		exit(Error);
	}
	(*SL)[i-1].data = e;

	return OK;
}

int LocateElem_SL(SLinkList *SL, ElemType e)
{
	//在静态单链线性表SL中查找第一值为 e 的元素
	//若找到，则返回它在SL中的位序，否则返回 0
	int i = 0;

	while ((*SL)[i].cur > 0)
	{
		if ((*SL)[i].data == e)
		{
			return (*SL)[i].cur;
		}
		++i;
	}

	return 0;
}

void ShowList_SL(SLinkList *SL, _Bool IsChar)
{
	int i = 0;
	while ((*SL)[i].cur > 0)
	{
		if (IsChar)
			printf("ID=%d, Data=%c\n", (*SL)[i].cur, (*SL)[i].data);
		else
			printf("ID=%d, Data=%d\n", (*SL)[i].cur, (*SL)[i].data);
		++i;
	}
}

/***************************DuLinkList动态双向链表***************************/

Status CreateList_DuL(DuLinkList *pDuL)
{
	*pDuL = (DuLinkList)malloc(sizeof(DuLNode));	//生成头节点
	if (*pDuL)
	{
		memset(*pDuL, 0, sizeof(DuLNode));
		return OK;
	}
	else
	{
		return Error;
	}
}

DuLinkList GetElemP_DuL(DuLinkList Dul, int i)
{
	// L为带头结点的单链表的头指针。
	// 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
	DuLinkList p;
	p = Dul;
	int j = 0;  // 初始化，p指向第一个结点，j为计数器
	while (p && j<i-1)   //顺指针向后查找，直到p指向第i个元素或p为空
	{
		p = p->next;
		++j;
	}
	if (!p || j>i-1)
		return NULL;  // 第i个元素不存在
	else
		return p;
}

Status ListInsert_DuL(DuLinkList DuL, int i, ElemType e)
{
	// 在带头结点的双链循环线性表L的第i个元素之前插入元素 e，
	// i的合法值为 1 <= i <= 表长 +1。
	DuLinkList p, s;

	p = GetElemP_DuL(DuL, i);  // 在L中确定第i个元素的位置指针p
	if (!p)
		return Error;
	if (!(s = (DuLinkList)malloc(sizeof(DuLNode))))
		return Error;
	memset(s, 0, sizeof(DuLNode));
	s->data = e;
	if (p->next)
	{
		p->next->prior = s;
	}
	s->prior = p;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete_Dul(DuLinkList DuL, int i, ElemType *e)
{
	//删除带头结点的双链循环线性表L的第i个元素，i的合法值为1<=i<=表长
	DuLinkList p;//, p1;
	
	if (!(p = GetElemP_DuL(DuL, i)))  // 在L中确定第i个元素的位置指针p
		return Error;                 // p=NULL, 即第i个元素不存在
	if (p->next)
	{
		*e = p->next->data;
		//p1 = p->next;
		if (p->next->next != NULL)
		{
			p->next->next->prior = p;
			free(p->next);
			p->next = p->next->next;
		}
		else
		{
			free(p->next);
			p->next = NULL;	
		}
		return OK;
	}
	else
	{
		return Error;
	}
}

void ClearNode(DuLinkList DuL)
{
	DuLinkList p;
	
	DuL = DuL->next;
	while (DuL != NULL)
	{
		p = DuL->next;
		free(DuL);
		DuL = p;
	}
}

void ShowList_DuL(char *s, DuLinkList DuL, _Bool IsChar)
{
	printf(s);
	printf("(");
	DuL = DuL->next;
	while (DuL != NULL)
	{
		if (IsChar)
		{
			printf(" %c ", DuL->data);
		}
		else
		{
			printf(" %d ", DuL->data);
		}
		DuL = DuL->next;
	}
	printf(")\n");
}
