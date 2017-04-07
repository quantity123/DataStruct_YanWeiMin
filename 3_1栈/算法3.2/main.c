#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\Func_3.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void LineEdit(SqStack *S)
{
	//�����ַ�ջS�����ն˽���һ�в����������ù��̵��������� 
	char ch, *temp;
	
	InitStack(S);	//�����ջ S
	printf("������һ��(#:�˸�@:����):\n");
	ch = getchar();	//���յ�һ���ַ�
	while (ch != EOF)	//EOFΪȫ�Ľ����� 
	{
		while (ch != EOF && ch != '\n')
		{
			switch (ch)
			{
				case '#': Pop(S, &ch); break;
				case '@': ClearStack(S); break;
				default: Push(S, ch); break;
			}
			ch = getchar();	//���ն˽�����һ���ַ� 
		}
		temp = S->base;
		while (temp != S->top)
		{
			printf("%c", *temp);
			++temp;
		}
		//����ջ�׵�ջ����ջ���ַ����������ù��̵�������
		ClearStack(S) ;
		printf("\n");
		if (ch != EOF)
		{
			printf("������һ��(#:�˸�@:����):\n");
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
