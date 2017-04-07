#include <stdio.h>
#include <stdlib.h>
#include "..\Func4.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	HString *S, T;
	char *chars;
	
	CreateStringHead(&S);
	
	printf("Test1:\n");
	
	
	chars = "FIBWQ\0";
	StrAssign(S, chars);
	printf("  S = ");
	printf(S->ch);
	printf("\n");
	
	chars = "YSDMOHV\0";
	StrAssign(&T, chars);
	printf("  T = ");
	printf(T.ch);
	printf("\n");

	if (StrInsert(S, 3, T) == 0)
	{
		printf("  StrInsert(S, 3, T) = OK\n");
	}
	else
	{
		printf("  StrInsert(S, 3, T) = Error\n");
	}
	printf("  S = ");
	printf(S->ch);
	printf("\n");
	
	ClearString(&T);
	ClearString(S);
	
	
	printf("Test4:\n");
	
	chars = "ABCDEFGHIJKLMN123456\0";
	StrAssign(S, chars);
	printf("  S = ");
	printf(S->ch);
	printf("\n");
	
	chars = "999888777NNN\0";
	StrAssign(&T, chars);
	printf("  T = ");
	printf(T.ch);
	printf("\n");

	if (StrInsert(S, 11, T) == 0)
	{
		printf("  StrInsert(S, 11, T) = OK\n");
	}
	else
	{
		printf("  StrInsert(S, 11, T) = Error\n");
	}
	printf("  S = ");
	printf(S->ch);
	printf("\n");
	
	ClearString(&T);
	ClearString(S);
	
	DestroyStringHead(&S);
	
	system("pause");
	
	return 0;
}
