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
	printf("SqQueue长度为%d\n", Len);
	
	EnQueue(&Q, 1);
	printf("1入队\n");
	EnQueue(&Q, 2);
	printf("2入队\n");
	EnQueue(&Q, 3);
	printf("3入队\n");
	Len = SqQueueLength(&Q);
	printf("SqQueue长度为%d\n", Len);
	
	int e;
	DeQueue(&Q, &e);
	printf("%d出队\n", e);
	DeQueue(&Q, &e);
	printf("%d出队\n", e);
	DeQueue(&Q, &e);
	printf("%d出队\n", e);
	Len = SqQueueLength(&Q);
	printf("SqQueue长度为%d\n", Len);
	return 0;
}
