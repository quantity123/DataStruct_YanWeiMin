#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\Func_3.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void conversion (int Num) 
{	
    //�������������һ���Ǹ�ʮ��������,��ӡ��������ֵ�İ˽�����.
    ElemType e;  
    SqStack S;
    InitStack(&S);      //�����ջ
    while (Num)
	{
    	Push(&S, Num % 8);
    	Num = Num / 8;
    }
    while (!StackEmpty(&S)) 
	{	
        Pop(&S, &e);
        printf("%d", e);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
/*
	SqStack S;
	ElemType e;
	
	memset(&S, 0, sizeof(S));
	InitStack(&S);
	Push(&S, 5);
	Pop(&S, &e);
	printf("%d", e);
*/
	 
	ElemType e;
	
	e = 3;
	printf("��%d, 10����ת8���� = ", e);
	conversion(e);
	
	e = 18;
	printf("��%d, 10����ת8���� = ", e);
	conversion(e);
	
	e = 71;
	printf("��%d, 10����ת8���� = ", e);
	conversion(e);
	
	e = 170;
	printf("��%d, 10����ת8���� = ", e);
	conversion(e);
	
	e = 1227;
	printf("��%d, 10����ת8���� = ", e);
	conversion(e);
	
	e = 1888;
	printf("��%d, 10����ת8���� = ", e);
	conversion(e);
	
	e = 3815;
	printf("��%d, 10����ת8���� = ", e);
	conversion(e);
	
	e = 4605;
	printf("��%d, 10����ת8���� = ", e);
	conversion(e);
	
	e = 4685;
	printf("��%d, 10����ת8���� = ", e);
	conversion(e);
	
	return 0;
}
