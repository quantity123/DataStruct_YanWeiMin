#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\func.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	SqList L1, L2, L3;
	ElemType e;
	char *str;
	char c;
	
	InitList_Sq(&L1);
	str = "L1 = ";
	ShowList(str, &L1, False);
	if (ListDelete_Sq(&L1, 1, &e) == OK)
	{
		str = "  ListDelete_Sq(L1, 1, e) = OK, L1 = ";
	}
	else
	{
		str = "  ListDelete_Sq(L1, 1, e) = Error, L1 = ";
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
	if (ListDelete_Sq(&L2, 11, &e) == OK)
	{
		str = "  ListDelete_Sq(L2, 11, e) = OK, L2 = ";
	}
	else
	{
		str = "  ListDelete_Sq(L2, 11, e) = Error, L2 = ";
	}
	ShowList(str, &L2, False);
	UnInitList_Sq(&L2);
	
	InitList_Sq(&L3);
	c = 'E';
	ListInsert_Sq(&L3, 1, (ElemType)c);
	c = 'F';
	ListInsert_Sq(&L3, 2, (ElemType)c);
	c = 'g';
	ListInsert_Sq(&L3, 3, (ElemType)c);
	c = 'H';
	ListInsert_Sq(&L3, 4, (ElemType)c);
	str = "L3 = ";
	ShowList(str, &L3, False);
	if (ListDelete_Sq(&L3, 3, &e) == OK)
	{
		str = "  ListDelete_Sq(L3, 3, e) = OK, L3 = ";
	}
	else
	{
		str = "  ListDelete_Sq(L3, 3, e) = Error, L3 = ";
	}
	ShowList(str, &L3, False);
	printf("e = %c\n", e);
	UnInitList_Sq(&L3);
	
	return 0;
}
