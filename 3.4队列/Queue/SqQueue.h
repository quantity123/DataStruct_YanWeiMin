#define MAXQSIZE 10	//�����г���

typedef struct 
{
	int *base;	//��ʼ���Ķ�̬�����ڴ�ռ�
	int front;	//ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear;	//βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��	
} SqQueue;
