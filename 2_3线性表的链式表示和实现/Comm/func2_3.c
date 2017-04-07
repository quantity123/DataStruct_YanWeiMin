#include <stdio.h>
#include <stdlib.h>
#include "func2_3.h"

/**************************LinkList��̬��������*******************************/

void CreateList_L(LinkList L, int N, _Bool IsChar)
{
	//��λ������n��Ԫ�ص�ֵ����������ͷ�ڵ�ĵ������Ա�
	int i;

	for (i = N; i > 0; --i)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));	//�����½ڵ�
		memset(p, 0, sizeof(LNode));
		if (IsChar)
			scanf("%c", &p->Data);	//����Ԫ��ֵ�ַ�
		else
			scanf("%d", &p->Data);	//����Ԫ��ֵ����
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
	//�ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
	LinkList p;
	int j = 0;
	Status Result = Error;

	while (L && j < i - 1)
	{
		//Ѱ�ҵ�i-1�����
		L = L->Next;
		++j;
	}
	if (!L || j > i-1)
		return Result;	//iС��1���ߴ��ڱ�
	p = (LinkList)malloc(sizeof(LNode));	//�����½��
	p->Data = e;
	p->Next = L->Next;	//����L��
	L->Next = p;

	Result = OK;
	return Result;
}

Status ListDelete_L(LinkList L, int i, ElemType *e)
{
	//�ڴ�ͷ�ڵ�ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
	Status Result = False;
	LinkList p, q;

	p = L;
	int j = 0;
	while (p->Next && j < i-1)	//Ѱ�ҵ�i����㣬����pָ����ǰ��
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
	//LΪ��ͷ�ڵ�ĵ������ͷָ��
	//����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�Error
	LinkList p;

	Status Result = Error;

	p = L->Next;
	int j = 1;	//��ʼ����pָ���һ���ڵ㣬jΪ������
	while (p && j<i)	//˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
	{
		p = p->Next;
		++j;
	}
	if (!p || j>i)
		return Error;	//��i��Ԫ�ز�����
	*e = p->Data;	//ȡ��i��Ԫ��

	Result = OK;
	return Result;
}

void MergeList_L(LinkList La, LinkList Lb, LinkList Lc)
{
	//��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
	//����La��Lb�õ��µĵ������Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
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
	while (La)	//����ʣ��La��
	{
		Lc->Next = La;
		La = La->Next;
		Lc = Lc->Next;
	}
	while (Lb)	//����ʣ��Lb��
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

/**************************SLinkList��̬��������*******************************/

void InitSpace_SL(SLinkList *SL)
{
	//��һά����SL�и���������һ����������SLΪͷָ��
	//0 ��ʾ��ָ��
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
	//�ھ�̬�������Ա�SL�в��ҵ�һֵΪ e ��Ԫ��
	//���ҵ����򷵻�����SL�е�λ�򣬷��򷵻� 0
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

/***************************DuLinkList��̬˫������***************************/

Status CreateList_DuL(DuLinkList *pDuL)
{
	*pDuL = (DuLinkList)malloc(sizeof(DuLNode));	//����ͷ�ڵ�
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
	// LΪ��ͷ���ĵ������ͷָ�롣
	// ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
	DuLinkList p;
	p = Dul;
	int j = 0;  // ��ʼ����pָ���һ����㣬jΪ������
	while (p && j<i-1)   //˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
	{
		p = p->next;
		++j;
	}
	if (!p || j>i-1)
		return NULL;  // ��i��Ԫ�ز�����
	else
		return p;
}

Status ListInsert_DuL(DuLinkList DuL, int i, ElemType e)
{
	// �ڴ�ͷ����˫��ѭ�����Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ�� e��
	// i�ĺϷ�ֵΪ 1 <= i <= �� +1��
	DuLinkList p, s;

	p = GetElemP_DuL(DuL, i);  // ��L��ȷ����i��Ԫ�ص�λ��ָ��p
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
	//ɾ����ͷ����˫��ѭ�����Ա�L�ĵ�i��Ԫ�أ�i�ĺϷ�ֵΪ1<=i<=��
	DuLinkList p;//, p1;
	
	if (!(p = GetElemP_DuL(DuL, i)))  // ��L��ȷ����i��Ԫ�ص�λ��ָ��p
		return Error;                 // p=NULL, ����i��Ԫ�ز�����
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
