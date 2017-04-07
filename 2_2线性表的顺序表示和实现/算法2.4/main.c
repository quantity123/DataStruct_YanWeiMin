#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\func.h"

void Show2_3()
{
	SqList L1, L2, L3, L4;
	char c;
	char *str;

	InitList_Sq(&L1);
	printf("InitList_Sq(L1), L1 = ()\n");
	c = 'a';
	ListInsert_Sq(&L1, 1, (ElemType)c);
	str = "  ListInsert_Sq(L1, 1, a), L1 = ";
	ShowList(str, &L1, False);
	c = 'h';
	ListInsert_Sq(&L1, 2, (ElemType)c);
	str = "  ListInsert_Sq(L1, 2, h), L1 = ";
	ShowList(str, &L1, False);
	c = 'l';
	ListInsert_Sq(&L1, 2, (ElemType)c);
	str = "  ListInsert_Sq(L1, 2, l), L1 = ";
	ShowList(str, &L1, False);
	UnInitList_Sq(&L1);

	InitList_Sq(&L2);
	printf("InitList_Sq(L2), L2 = ()\n");
	c = 'k';
	ListInsert_Sq(&L2, 1, (ElemType)c);
	str = "  ListInsert_Sq(L2, 1, k), L2 = ";
	ShowList(str, &L2, False);
	c = 'w';
	ListInsert_Sq(&L2, 1, (ElemType)c);
	str = "  ListInsert_Sq(L2, 1, w), L2 = ";
	ShowList(str, &L2, False);
	c = 'b';
	ListInsert_Sq(&L2, 3, (ElemType)c);
	str = "  ListInsert_Sq(L2, 3, b), L2 = ";
	ShowList(str, &L2, False);
	UnInitList_Sq(&L2);

	InitList_Sq(&L3);
	printf("InitList_Sq(L3), L3 = ()\n");
	c = 's';
	ListInsert_Sq(&L3, 1, (ElemType)c);
	str = "  ListInsert_Sq(L3, 1, s), L3 = ";
	ShowList(str, &L3, False);
	c = 'w';
	ListInsert_Sq(&L3, 1, (ElemType)c);
	str = "  ListInsert_Sq(L3, 1, w), L3 = ";
	ShowList(str, &L3, False);
	c = 'd';
	ListInsert_Sq(&L3, 3, (ElemType)c);
	str = "  ListInsert_Sq(L3, 3, d), L3 = ";
	ShowList(str, &L3, False);
	UnInitList_Sq(&L3);

	InitList_Sq(&L4);
	printf("InitList_Sq(L4), L4 = ()\n");
	c = 'u';
	ListInsert_Sq(&L4, 1, (ElemType)c);
	str = "  ListInsert_Sq(L4, 1, u), L4 = ";
	ShowList(str, &L4, False);
	c = 'p';
	ListInsert_Sq(&L4, 1, (ElemType)c);
	str = "  ListInsert_Sq(L4, 1, p), L4 = ";
	ShowList(str, &L4, False);
	c = 'x';
	ListInsert_Sq(&L4, 1, (ElemType)c);
	str = "  ListInsert_Sq(L4, 1, x), L4 = ";
	ShowList(str, &L4, False);
	c = 'l';
	ListInsert_Sq(&L4, 1, (ElemType)c);
	str = "  ListInsert_Sq(L4, 1, l), L4 = ";
	ShowList(str, &L4, False);
	UnInitList_Sq(&L4);
}

void Show2_4()
{
	SqList L1, L2;
	char c;
	char *str;

	InitList_Sq(&L1);
	c = 'G';
	ListInsert_Sq(&L1, 1, (ElemType)c);
	c = 'J';
	ListInsert_Sq(&L1, 2, (ElemType)c);
	c = 'M';
	ListInsert_Sq(&L1, 3, (ElemType)c);
	c = 'O';
	ListInsert_Sq(&L1, 4, (ElemType)c);
	str = "L1 = ";
	ShowList(str, &L1, False);
	c = 'e';
	if (ListInsert_Sq(&L1, 3, (ElemType)c) == OK)
	{
		str = "  ListInsert_Sq(L1, 3, e) = OK, L1 = ";
	}
	else
	{
		str = "  ListInsert_Sq(L1, 3, e) = Error, L1 = ";
	}
	ShowList(str, &L1, False);
	UnInitList_Sq(&L1);

	InitList_Sq(&L2);
	c = 'A';
	ListInsert_Sq(&L2, 1, (ElemType)c);
	c = 'B';
	ListInsert_Sq(&L2, 2, (ElemType)c);
	c = 'C';
	ListInsert_Sq(&L2, 3, (ElemType)c);
	c = 'D';
	ListInsert_Sq(&L2, 4, (ElemType)c);
	str = "L2 = ";
	ShowList(str, &L2, False);
	c = 'e';
	if (ListInsert_Sq(&L2, 9, (ElemType)c) == OK)
	{
		str = "  ListInsert_Sq(L2, 9, e) = OK, L2 = ";
	}
	else
	{
		str = "  ListInsert_Sq(L2, 9, e) = Error, L2 = ";
	}
	ShowList(str, &L2, False);
	UnInitList_Sq(&L2);
}

int main(int argc, char *argv[])
{
	printf("******Show2.3**********************************\n");
	Show2_3();
	printf("\n");
	printf("\n");
	printf("******Show2.4**********************************\n");
	Show2_4();
	return 0;
}
