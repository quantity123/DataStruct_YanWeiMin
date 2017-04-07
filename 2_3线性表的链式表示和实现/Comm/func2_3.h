#include <strings.h>
#include "..\..\Comm\CommDef.h"

//动态单向链表结构 
typedef struct LNode
{
	ElemType Data;
	struct LNode *Next;
} LNode, *LinkList;

#define MAXSIZE 30	//链表最大长度
//静态单向链表结构 
typedef struct
{
	ElemType data;
	int cur;	
} component, SLinkList[MAXSIZE];

//动态双向链表结构
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
} DuLNode, *DuLinkList;
