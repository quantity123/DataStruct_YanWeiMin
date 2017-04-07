#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\func2_3.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	DuLinkList DuL1;
	char* s;
	Status st;
	ElemType e;
	
	st = CreateList_DuL(&DuL1);
	if (st == Error)
		exit(Error);
	s = "DuL1 = ";
	ShowList_DuL(s, DuL1, True);
	
	printf("ListDelete_Dul(DuL1, 1, e) : ");
	st = ListDelete_Dul(DuL1, 1, &e);
	if (st == OK)
	{
		s = "OK, e = %d, ";
		printf(s, e);
	}
	else
	{
		s = "Error, ";
		printf(s);
	}
	s = "DuL1 = ";
	ShowList_DuL(s, DuL1, True);
	
	ListInsert_DuL(DuL1, 1, (ElemType)'a');
	ListInsert_DuL(DuL1, 2, (ElemType)'b');
	ListInsert_DuL(DuL1, 3, (ElemType)'c');
	ListInsert_DuL(DuL1, 4, (ElemType)'d');
	s = "DuL1 = ";
	ShowList_DuL(s, DuL1, True);
	printf("ListDelete_Dul(DuL1, 3, e) : ");
	st = ListDelete_Dul(DuL1, 3, &e);
	if (st == OK)
	{
		s = "OK, e = %c, ";
		printf(s, e);
	}
	else
	{
		s = "Error, ";
		printf(s);
	}
	s = "DuL1 = ";
	ShowList_DuL(s, DuL1, True);
	
	ClearNode(DuL1);
	return 0;
}
