#include <stdio.h>
#include <stdlib.h>
#include "..\Comm.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	BiTree RootTree;
	
	CreateBiTree(&RootTree);
	
	printf("T = ");
	
	ShowBiTree(RootTree);
	
	DestroyBiTree(&RootTree);
	
	printf("\n");
	system("pause");
	return 0;
}
