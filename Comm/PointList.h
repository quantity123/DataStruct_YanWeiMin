#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct List
{
	unsigned int Count;
	void **Array;
} List, *PList;
