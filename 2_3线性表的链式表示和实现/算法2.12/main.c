#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\func2_3.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	LNode La, Lb, Lc;
	char *s;
	
	memset(&La, 0, sizeof(La));
	ListInsert_L(&La, 1, (ElemType)'A');
	ListInsert_L(&La, 2, (ElemType)'C');
	ListInsert_L(&La, 3, (ElemType)'E');
	ListInsert_L(&La, 4, (ElemType)'G');
	ListInsert_L(&La, 5, (ElemType)'I');
	s = "La = ";
	ShowList_L(s, &La, True);
	
	memset(&Lb, 0, sizeof(Lb));
	ListInsert_L(&Lb, 1, (ElemType)'B');
	ListInsert_L(&Lb, 2, (ElemType)'D');
	ListInsert_L(&Lb, 3, (ElemType)'F');
	ListInsert_L(&Lb, 4, (ElemType)'H');
	ListInsert_L(&Lb, 5, (ElemType)'J');
	s = "Lb = ";
	ShowList_L(s, &Lb, True);
	
	printf("MergeList_L(La, Lb, Lc)\n");
	MergeList_L(&La, &Lb, &Lc);
	s = "Lc = ";
	ShowList_L(s, &Lc, True);
	
	Destroy_L(&Lc);

	return 0;
}
