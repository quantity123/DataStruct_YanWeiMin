#include <stdio.h>
#include <stdlib.h>
#include "..\Comm.h"
#include "PointList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	BiTree TreeRoot;
	PList pList;
	
	CreateUnsignedIntList(&pList);
	
	//CreateTreeRoot(&TreeRoot);
	//BuildTreeNode(TreeRoot);

	
	ClearUnsignedIntList(pList);
	DestroyUnsignedIntList(&pList);
	
	
	
	system("pause");
	return 0;
}
