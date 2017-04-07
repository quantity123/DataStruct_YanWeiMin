#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\Func_3.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void conversion (int Num) 
{	
    //对于输入的任意一个非负十进制整数,打印输出与其等值的八进制数.
    ElemType e;  
    SqStack S;
    InitStack(&S);      //构造空栈
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
	printf("数%d, 10进制转8进制 = ", e);
	conversion(e);
	
	e = 18;
	printf("数%d, 10进制转8进制 = ", e);
	conversion(e);
	
	e = 71;
	printf("数%d, 10进制转8进制 = ", e);
	conversion(e);
	
	e = 170;
	printf("数%d, 10进制转8进制 = ", e);
	conversion(e);
	
	e = 1227;
	printf("数%d, 10进制转8进制 = ", e);
	conversion(e);
	
	e = 1888;
	printf("数%d, 10进制转8进制 = ", e);
	conversion(e);
	
	e = 3815;
	printf("数%d, 10进制转8进制 = ", e);
	conversion(e);
	
	e = 4605;
	printf("数%d, 10进制转8进制 = ", e);
	conversion(e);
	
	e = 4685;
	printf("数%d, 10进制转8进制 = ", e);
	conversion(e);
	
	return 0;
}
