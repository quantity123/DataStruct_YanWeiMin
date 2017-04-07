#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\func2_3.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	LNode L1, L5, L6;
	char *s;
	
	memset(&L1, 0, sizeof(L1));
	CreateList_L(&L1, 0, True);
	s = "L1 = ";
	ShowList_L(s, &L1, True);
	printf("  ListInsert_L(L1, 1, 'g') = ");
	if (ListInsert_L(&L1, 1, (ElemType)'g') == OK)
	{
		s = "OK£¬ L1 = ";
	}
	else
	{
		s = "Error£¬ L1 = ";
	}
	ShowList_L(s, &L1, True);
	Destroy_L(&L1);
	
	memset(&L5, 0, sizeof(L5));
	CreateList_L(&L5, 6, True);
	s = "L5 = ";
	ShowList_L(s, &L5, True);
	printf("  ListInsert_L(L5, 14, 'g') = ");
	if (ListInsert_L(&L5, 14, (ElemType)'g') == OK)
	{
		s = "OK£¬ L5 = ";
	}
	else
	{
		s = "Error£¬ L5 = ";
	}
	ShowList_L(s, &L5, True);
	Destroy_L(&L5);
	
	memset(&L6, 0, sizeof(L6));
	CreateList_L(&L6, 6, True);
	s = "L6 = ";
	ShowList_L(s, &L6, True);
	printf("  ListInsert_L(L6, 3, 'u') = ");
	if (ListInsert_L(&L6, 3, (ElemType)'u') == OK)
	{
		s = "OK£¬ L6 = ";
	}
	else
	{
		s = "Error£¬ L6 = ";
	}
	ShowList_L(s, &L6, True);
	Destroy_L(&L6);
	
	return 0;
}
