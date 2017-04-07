#define MAXQSIZE 10	//最大队列长度

typedef struct 
{
	int *base;	//初始化的动态分配内存空间
	int front;	//头指针，若队列不空，指向队列头元素
	int rear;	//尾指针，若队列不空，指向队列尾元素的下一个位置	
} SqQueue;
