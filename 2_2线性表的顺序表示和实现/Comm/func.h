#include "..\..\Comm\CommDef.h"

//顺序表头结构体类型定义
typedef struct
{
	ElemType *elem;	//存储空间基址
	int length;	//当前长度
	int listsize;	//当前分配的存储容量(以sizeof(ElemType)为单位)
} SqList, *pSqList;
