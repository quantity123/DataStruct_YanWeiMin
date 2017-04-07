#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\func2_3.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	LNode L1, L2, L3;
	char *s;
	ElemType e;
	
	memset(&L1, 0, sizeof(L1));
	s = "L1 = ";
	ShowList_L(s, &L1, True);
	printf("  ListDelete_L(L1, 1, e) = ");
	if (ListDelete_L(&L1, 1, &e) == OK)
	{
		s = "OK£¬e = \'%c\', ";
		printf(s, e);
	}
	else
	{
		s = "Error, ";
		printf(s);
	}
	s = "L1 = ";
	ShowList_L(s, &L1, True);
	Destroy_L(&L1);
		
	memset(&L2, 0, sizeof(L2));
	ListInsert_L(&L2, 1, (ElemType)'A');
	ListInsert_L(&L2, 2, (ElemType)'B');
	ListInsert_L(&L2, 3, (ElemType)'C');
	ListInsert_L(&L2, 4, (ElemType)'D');
	ListInsert_L(&L2, 5, (ElemType)'E');
	s = "L2 = ";
	ShowList_L(s, &L2, True);
	printf("  ListDelete_L(L2, 10, e) = ");
	if (ListDelete_L(&L2, 10, &e) == OK)
	{
		s = "OK£¬e = \'%c\'";
		printf(s, e);
	}
	else
	{
		s = "Error, ";
		printf(s);
	}
	s = "L2 = ";
	ShowList_L(s, &L2, True);
	Destroy_L(&L2);
	
	memset(&L3, 0, sizeof(L3));
	ListInsert_L(&L3, 1, (ElemType)'A');
	ListInsert_L(&L3, 2, (ElemType)'B');
	ListInsert_L(&L3, 3, (ElemType)'C');
	ListInsert_L(&L3, 4, (ElemType)'D');
	ListInsert_L(&L3, 5, (ElemType)'E');
	s = "L3 = ";
	ShowList_L(s, &L3, True);
	printf("  ListDelete_L(L3, 3, e) = ");
	if (ListDelete_L(&L3, 3, &e) == OK)
	{
		s = "OK£¬e = \'%c\'";
		printf(s, e);
	}
	else
	{
		s = "Error, ";
		printf(s);
	}
	s = "L3 = ";
	ShowList_L(s, &L3, True);
	Destroy_L(&L3);

	return 0;
}
