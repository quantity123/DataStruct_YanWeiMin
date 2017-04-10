#include <stdio.h>
#include <stdlib.h>
#include "SqQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	SqQueue Q;
	int Len;
	
	InitSqQueue(&Q);
	Len = SqQueueLength(&Q);
	printf("SqQueue����Ϊ%d\n", Len);
	
	EnQueue(&Q, 1);
	printf("1���\n");
	EnQueue(&Q, 2);
	printf("2���\n");
	EnQueue(&Q, 3);
	printf("3���\n");
	Len = SqQueueLength(&Q);
	printf("SqQueue����Ϊ%d\n", Len);
	
	int e;
	DeQueue(&Q, &e);
	printf("%d����\n", e);
	DeQueue(&Q, &e);
	printf("%d����\n", e);
	DeQueue(&Q, &e);
	printf("%d����\n", e);
	Len = SqQueueLength(&Q);
	printf("SqQueue����Ϊ%d\n", Len);
	return 0;
}
