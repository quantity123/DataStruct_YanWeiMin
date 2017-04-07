#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "..\..\Comm\CommDef.h"

typedef struct List
{
	unsigned int Count;
	void **Array;
} List, *PList;
