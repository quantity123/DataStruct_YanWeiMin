#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\func2_3.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	SLinkList SL1;
	int i;
	
	memset(&SL1, 0, sizeof(SL1));
	InitSpace_SL(&SL1);
	
	ShowList_SL(&SL1);

	system("pause");

	return 0;
}
