#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "..\Comm\CommDef.h"

typedef struct BiTNode
{
	ElemType Data;
	struct BiTNode *Parent, *lChild, *rChild;	//×óÓÒ×ÓÊ÷
}BiTNode, *BiTree;
