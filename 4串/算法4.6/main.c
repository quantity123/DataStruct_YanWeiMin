#include <stdio.h>
#include <stdlib.h>
#include "..\Func4.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	HString S, T;
	
	printf("Test1:\n");
	
	char *CS = "WQPRHFEERRR\0";
	StrAssign(&S, CS);
	printf("  S = ");
	printf(S.ch);
	printf("\n");
	
	CS = "HF\0";
	StrAssign(&T, CS);
	printf("  T = ");
	printf(T.ch);
	printf("\n");
	
	printf("  Index(S, T) = ");
	int r;
	r = Index(&S, &T);
	printf("%d\n", r);
	

	printf("Test2:\n");
	
	CS = "TSGOHCUWWBZXI\0";
	StrAssign(&S, CS);
	printf("  S = ");
	printf(S.ch);
	printf("\n");
	
	CS = "UWWBZX\0";
	StrAssign(&T, CS);
	printf("  T = ");
	printf(T.ch);
	printf("\n");
	
	printf("  Index(S, T) = ");
	r = Index(&S, &T);
	printf("%d\n", r);
	
	system("pause");
	
	return 0;
}
