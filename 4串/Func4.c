#include <stdlib.h>
#include <strings.h>
#include "Func4.h"

_Bool CreateStringHead(HString **S)
{
	*S = (HString *)malloc(sizeof(HString));
	if (*S)
	{
		memset(*S, 0, sizeof(HString));
		return 1;
	}
	else
		return 0;
}

_Bool DestroyStringHead(HString **S)
{
	if (*S)
		free(*S);
}

_Bool StrAssign(HString *S, char *chars)
{
	//生成一个其值等于串常量 chars 的串 T
	short i;
//	char *c;
	/*
		for (i=0, c=chars; *c; ++i, ++c)
		{
			if (i == 0)
				S->ch = (char *)malloc((i+1) * sizeof(char));
			else
				S->ch = (char *)realloc(S->ch, (i+1) * sizeof(char));
			if (!S->ch)
				return 0;
			S->ch[i] = chars[i];
			S->length = i+1;
		}
		*/
	i = 1;
	while (1)
	{
		if (i == 1)
			S->ch = (char *)malloc(i * sizeof(char));
		else
			S->ch = (char *)realloc(S->ch, i * sizeof(char));
		if (!S->ch)
			return 0;
		S->ch[i-1] = chars[i-1];
		if (chars[i-1] == '\0')
			break;
		S->length = i;
		++i;
	}
	return 0;
}

void ClearString(HString *S)
{
	if (S->ch)
		free(S->ch);
	memset(S, 0, sizeof(HString));
}

int StrInsert(HString *S, int pos, HString T)
{
	// 1 <= pos <= StrLength(S) + 1，在串 S 的第 pos 个字符之前插入串 T
	if (pos < 1 || pos > S->length+1)
		return -1;	//pos不合法
	if (T.length)
	{
		//T非空，则重新分配空间，插入 T
		S->ch = (char *)realloc(S->ch, (S->length+T.length+1) * sizeof(char));
		if (!S->ch)
			return -2;
		int i;
		for (i=S->length-1; i>=pos-1; --i)	//为插入T而腾出位置
		{
			S->ch[i+T.length] = S->ch[i];
		}
		for (i=0; i<=T.length-1; i++)	//插入T字符串
		{
			S->ch[pos-1+i] = T.ch[i];
		}
		S->length += T.length;
		S->ch[S->length+1] = '\0';
	}
	return 0;
}

_Bool Match(HString *S, int S_index, HString *T)
{
	int i;

	for (i=1; i < T->length; i++)
	{
		if (S->ch[S_index+i] != T->ch[i])
			return 0;
	}
	return 1;
}

int Index(HString *S, HString *T)
{
	int i;
	
	if ((S->length > 1) && (T->length > 1))
	{
		for (i = 0; i < S->length; i++)
		{
			if (S->ch[i] == T->ch[0])
			{	
				if (Match(S, i, T))
				{
					return i + 1;
				}
			}
		}
	}
	return 0;
}

_Bool Match_KMP(HString *S, int index, HString *T, int *retrn_i)
{
	int i;

	for (i=1; i < T->length; i++)
	{
		if (*retrn_i == -1)
		{
			if (S->ch[index+i] == T->ch[0])
				*retrn_i = index+i;
		}
		if (S->ch[index+i] != T->ch[i])
			return 0;
	}
	if (*retrn_i == -1)
	{
		*retrn_i = T->length-1;
	}
	return 1;
}

int Index_KMP(HString *S, HString *T)
{
	int i = 0;
	int retrn_i;
	
	if ((S->length > 1) && (T->length > 1))
	{
		while ((S->length - i) >= T->length)
		{
			if (S->ch[i] == T->ch[0])
			{	
				retrn_i = -1;
				if (Match_KMP(S, i, T, &retrn_i))
				{
					return i + 1;
				}
				i = retrn_i;
			}
		}
	}
}
