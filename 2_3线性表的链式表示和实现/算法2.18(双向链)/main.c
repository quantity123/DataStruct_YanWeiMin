#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\func2_3.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	DuLinkList DuL1;
	char* s;
	Status st;

	st = CreateList_DuL(&DuL1);
	if (st == Error)
		exit(Error);
	memset(DuL1, 0, sizeof(DuLNode));
	s = "DuL1 = ";
	ShowList_DuL(s, DuL1, True);

	printf("ListInsert_DuL(Dul1, 1, \'a\') : ");
	st = ListInsert_DuL(DuL1, 1, (ElemType)'a');
	if (st = OK)
	{
		s = "OK, Dul1 = ";
	}
	else
	{
		s = "Error, Dul1 = ";
	}
	ShowList_DuL(s, DuL1, True);
	ClearNode(DuL1);


	ListInsert_DuL(DuL1, 1, (ElemType)'a');
	ListInsert_DuL(DuL1, 2, (ElemType)'b');
	ListInsert_DuL(DuL1, 3, (ElemType)'c');
	s= "DuL1 = ";
	ShowList_DuL(s, DuL1, True);
	printf("ListInsert_DuL(Dul1, 7, \'d\') : ");
	st = ListInsert_DuL(DuL1, 7, (ElemType)'d');
	if (st == OK)
	{
		s = "OK, Dul1 = ";
	}
	else
	{
		s = "Error, Dul1 = ";
	}
	ShowList_DuL(s, DuL1, True);
	printf("ListInsert_DuL(Dul1, 3, \'d\') : ");
	st = ListInsert_DuL(DuL1, 3, (ElemType)'d');
	if (st == OK)
	{
		s = "OK, Dul1 = ";
	}
	else
	{
		s = "Error, Dul1 = ";
	}
	ShowList_DuL(s, DuL1, True);
	ClearNode(DuL1);
	
	

	system("pause");
	return 0;
}
