#include <stdio.h>
#include <stdlib.h>
#include "..\Comm\func.h"

void MergeList_Sq(pSqList La, pSqList Lb, pSqList Lc)
{
	//��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢La��Lb�õ��µ�˳�����Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
	ElemType *pa = La->elem;
	ElemType *pb = Lb->elem;
	Lc->listsize = Lc->length = La->length + Lb->length;
	ElemType *pc = Lc->elem = (ElemType *)malloc(Lc->listsize * sizeof(ElemType));
	if (!Lc->elem)	//�洢����ʧ��
		exit(OverFlow);
	ElemType *pa_last = La->elem + La->length - 1;
	ElemType *pb_last = Lb->elem + Lb->length - 1;
	while (pa <= pa_last && pb <= pb_last)	//�鲢
	{
		if (*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last)	//����La��ʣ��Ԫ��
		*pc++ = *pa++;
	while (pb <= pb_last)	//����Lb��ʣ��Ԫ��
		*pc++ = *pb++;
}

Status Test1(pSqList La, pSqList Lb, pSqList Lc)
{
	Status Result = Error;
	
	printf("Test1��\n");
	
	char *str;
	ListInsert_Sq(La, 1, 30);
	ListInsert_Sq(La, 2, 39);
	ListInsert_Sq(La, 3, 44);
	ListInsert_Sq(La, 4, 81);
	ListInsert_Sq(La, 5, 93);
	str = "  LIST A = ";
	ShowList(str, La, True);

	ListInsert_Sq(Lb, 1, 9);
	ListInsert_Sq(Lb, 2, 12);
	ListInsert_Sq(Lb, 3, 23);
	ListInsert_Sq(Lb, 4, 25);
	ListInsert_Sq(Lb, 5, 34);
	ListInsert_Sq(Lb, 6, 38);
	ListInsert_Sq(Lb, 7, 55);
	ListInsert_Sq(Lb, 8, 79);
	ListInsert_Sq(Lb, 9, 95);
	str = "  LIST B = ";
	ShowList(str, Lb, True);

	MergeList_Sq(La, Lb, Lc);
	str = "  LIST C = Merge(A, B) = ";
	ShowList(str, Lc, True);
	
	ListClear(La);
	ListClear(Lb);
	ListClear(Lc);
	
	Result = OK;
	return Result;
}

Status Test2(pSqList La, pSqList Lb, pSqList Lc)
{
	Status Result = Error;
	
	printf("Test2��\n");
	
	char *str;
	ListInsert_Sq(La, 1, 6);
	ListInsert_Sq(La, 2, 21);
	ListInsert_Sq(La, 3, 29);
	ListInsert_Sq(La, 4, 39);
	ListInsert_Sq(La, 5, 50);
	ListInsert_Sq(La, 6, 63);
	ListInsert_Sq(La, 7, 68);
	ListInsert_Sq(La, 8, 97);
	str = "  LIST A = ";
	ShowList(str, La, True);

	ListInsert_Sq(Lb, 1, 28);
	ListInsert_Sq(Lb, 2, 30);
	ListInsert_Sq(Lb, 3, 31);
	ListInsert_Sq(Lb, 4, 67);
	ListInsert_Sq(Lb, 5, 68);
	ListInsert_Sq(Lb, 6, 70);
	ListInsert_Sq(Lb, 7, 91);
	ListInsert_Sq(Lb, 8, 96);
	str = "  LIST B = ";
	ShowList(str, Lb, True);

	MergeList_Sq(La, Lb, Lc);
	str = "  LIST C = Merge(A, B) = ";
	ShowList(str, Lc, True);
	
	ListClear(La);
	ListClear(Lb);
	ListClear(Lc);
	
	Result = OK;
	return Result;
}

Status Test5(pSqList La, pSqList Lb, pSqList Lc)
{
	Status Result = Error;
	
	printf("Test5��\n");
	
	char *str;
	ListInsert_Sq(La, 1, 7);
	ListInsert_Sq(La, 2, 23);
	ListInsert_Sq(La, 3, 27);
	ListInsert_Sq(La, 4, 28);
	ListInsert_Sq(La, 5, 43);
	ListInsert_Sq(La, 6, 67);
	ListInsert_Sq(La, 7, 73);
	str = "  LIST A = ";
	ShowList(str, La, True);

	ListInsert_Sq(Lb, 1, 0);
	ListInsert_Sq(Lb, 2, 23);
	ListInsert_Sq(Lb, 3, 83);
	str = "  LIST B = ";
	ShowList(str, Lb, True);

	MergeList_Sq(La, Lb, Lc);
	str = "  LIST C = Merge(A, B) = ";
	ShowList(str, Lc, True);
	
	ListClear(La);
	ListClear(Lb);
	ListClear(Lc);
	
	Result = OK;
	return Result;
}

int main(int argc, char *argv[])
{
	SqList La, Lb, Lc;
	
	if (InitList_Sq(&La) != OK)
	{
		printf("Test1��La_InitList_Sqʧ�ܣ�");
		exit(-10);
	}
	
	if (InitList_Sq(&Lb) != OK)
	{
		printf("Test1��Lb_InitList_Sqʧ�ܣ�");
		exit(-11);
	}
	
	if (InitList_Sq(&Lc) != OK)
	{
		printf("Test1��Lc_InitList_Sqʧ�ܣ�");
		exit(-12);
	}
	
	if (Test1(&La, &Lb, &Lc) == Error)
		exit(-1);
		
	if (Test2(&La, &Lb, &Lc) == Error)
		exit(-2);
	
	if (Test5(&La, &Lb, &Lc) == Error)
		exit(-5);

	UnInitList_Sq(&La);
	UnInitList_Sq(&Lb);
	UnInitList_Sq(&Lc);
	
	return 0;
}
