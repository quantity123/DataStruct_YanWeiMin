#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "..\Comm\func2_3.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	LNode L1;
	char *s;
	
	memset(&L1, 0, sizeof(L1));
	CreateList_L(&L1, 0, False);
	printf("CreateList_L(L1, 0)\n");
	s = "  L1 = ";
	ShowList_L(s, &L1, False);
	Destroy_L(L1);
	
	memset(&L1, 0, sizeof(L1));
	CreateList_L(&L1, 11, False);
	printf("CreateList_L(L2, 11)\n");
	s = "  L2 = ";
	ShowList_L(s, &L1, False);
	Destroy_L(L1);
	
	return 0;
}
