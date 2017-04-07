#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\func2_3.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	SLinkList SL;
	
	memset(&SL, 0, sizeof(SL));
	InitSpace_SL(&SL);
	SetData_SL(&SL, 1, (ElemType)'A');
	SetData_SL(&SL, 2, (ElemType)'B');
	SetData_SL(&SL, 3, (ElemType)'C');
	SetData_SL(&SL, 4, (ElemType)'D');
	SetData_SL(&SL, 5, (ElemType)'E');
	SetData_SL(&SL, 6, (ElemType)'F');
	SetData_SL(&SL, MAXSIZE, (ElemType)'Z');
	ShowList_SL(&SL, True);
	
	int i;
	
	printf("  LocateElem_SL(SL, 'A') = ");
	i = LocateElem_SL(SL, (ElemType)'A');
	printf("%d\n", i);
	
	printf("  LocateElem_SL(SL, 'E') = ");
	i = LocateElem_SL(SL, (ElemType)'E');
	printf("%d\n", i);
	
	printf("  LocateElem_SL(SL, 'X') = ");
	i = LocateElem_SL(SL, (ElemType)'X');
	printf("%d\n", i);
	
	system("pause");
	return 0;
}
