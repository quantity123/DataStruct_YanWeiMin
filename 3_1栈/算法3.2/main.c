#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\Func_3.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void LineEdit(SqStack *S)
{
	//利用字符栈S，从终端接收一行并传送至调用过程的数据区。 
	char ch, *temp;
	
	InitStack(S);	//构造空栈 S
	printf("请输入一行(#:退格；@:清行):\n");
	ch = getchar();	//接收第一个字符
	while (ch != EOF)	//EOF为全文结束符 
	{
		while (ch != EOF && ch != '\n')
		{
			switch (ch)
			{
				case '#': Pop(S, &ch); break;
				case '@': ClearStack(S); break;
				default: Push(S, ch); break;
			}
			ch = getchar();	//从终端接收下一个字符 
		}
		temp = S->base;
		while (temp != S->top)
		{
			printf("%c", *temp);
			++temp;
		}
		//将从栈底到栈顶的栈内字符传送至调用过程的数据区
		ClearStack(S) ;
		printf("\n");
		if (ch != EOF)
		{
			printf("请输入一行(#:退格；@:清行):\n");
			ch = getchar();
		}
	}
}

int main(int argc, char *argv[])
{
	SqStack *S;
	
	CreateStack(&S);
	
	LineEdit(S);
	
	DestroyStack(&S);
	
	return 0;
}
