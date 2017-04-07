#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\func.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	SqList L1, L2, L3;
	ElemType e;
	char c;
	char *str;
	int Index;
	
	InitList_Sq(&L1);
	str = "L1 = ";
	ShowList(str, &L1, False);
	e = (char)'N';
	Index = LocateElem_Sq(&L1, e);
	str = "  LocateElem_Sq(L1, N) = %d\n";
	printf(str, Index);
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
	e = (char)'N';
	Index = LocateElem_Sq(&L2, e);
	str = "  LocateElem_Sq(L2, N) = %d\n";
	printf(str, Index);
	UnInitList_Sq(&L2);
	
	InitList_Sq(&L3);
	c = 'A';
	ListInsert_Sq(&L3, 1, (ElemType)c);
	c = 'B';
	ListInsert_Sq(&L3, 2, (ElemType)c);
	c = 'C';
	ListInsert_Sq(&L3, 3, (ElemType)c);
	c = 'D';
	ListInsert_Sq(&L3, 4, (ElemType)c);
	c = 'E';
	ListInsert_Sq(&L3, 4, (ElemType)c);
	c = 'f';
	ListInsert_Sq(&L3, 4, (ElemType)c);
	c = 'G';
	ListInsert_Sq(&L3, 4, (ElemType)c);
	str = "L3 = ";
	ShowList(str, &L3, False);
	e = (char)'f';
	Index = LocateElem_Sq(&L3, e);
	str = "  LocateElem_Sq(L3, f) = %d\n";
	printf(str, Index);
	UnInitList_Sq(&L3);
	
	return 0;
}
