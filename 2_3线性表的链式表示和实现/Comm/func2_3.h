#include <strings.h>
#include "..\..\Comm\CommDef.h"

//��̬��������ṹ 
typedef struct LNode
{
	ElemType Data;
	struct LNode *Next;
} LNode, *LinkList;

#define MAXSIZE 30	//������󳤶�
//��̬��������ṹ 
typedef struct
{
	ElemType data;
	int cur;	
} component, SLinkList[MAXSIZE];

//��̬˫������ṹ
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
} DuLNode, *DuLinkList;
