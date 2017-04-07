#include "PointList.h"

void CreateUnsignedIntList(PList *ppList)
{
	*ppList = (PList)malloc(sizeof(List));
	memset(*ppList, 0, sizeof(List));
}

void DestroyUnsignedIntList(PList *ppList)
{
	free(*ppList);
}

void ClearUnsignedIntList(PList pList)
{
	free(pList->Array);
	pList->Count = 0;
}

void Add(PList pList, void *P)
{
	if (pList->Count == 0)
	{
		pList->Array = malloc(sizeof(void *));
		pList->Array[0] = P;
	}
	else if (pList->Count > 0)
	{
		pList->Array = realloc(pList->Array, (pList->Count+1) * sizeof(void *));
		pList->Array[pList->Count] = P;
	}
	++pList->Count;
}

void Delete(PList pList, unsigned int Index)
{
	unsigned int i;
	
	for (i = Index; i < pList->Count; i++)
	{
		pList->Array[i-1] = pList->Array[i];
	}
	--pList->Count;
	pList->Array = realloc(pList->Array, pList->Count * sizeof(void *));
}

void ShowList(PList pList)
{
	unsigned int i;
	
	for (i = 0; i < pList->Count; i++)
	{
		printf("%d ", *(unsigned int *)pList->Array[i]);
	}
	printf("\n");
}
