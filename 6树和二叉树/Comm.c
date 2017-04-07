
#include <time.h>
#include "Comm.h"

void CreateTwoSubNode(BiTree TreeNode)
{
	if (TreeNode->Data <= 7)
	{
		TreeNode->lChild = (BiTree)malloc(sizeof(BiTNode));	//创建左子分支
		memset(TreeNode->lChild, 0, sizeof(BiTNode));
		TreeNode->lChild->Data = TreeNode->Data * 2;
		CreateTwoSubNode(TreeNode->lChild);
		
		TreeNode->rChild = (BiTree)malloc(sizeof(BiTNode));	//创建右子分支
		memset(TreeNode->rChild, 0, sizeof(BiTNode));
		TreeNode->rChild->Data = TreeNode->Data * 2 + 1;
		CreateTwoSubNode(TreeNode->rChild);
	}
}

void CreateBiTree(BiTree *RootTree)
{	
	*RootTree = (BiTree)malloc(sizeof(BiTNode));
	memset(*RootTree, 0, sizeof(BiTNode));
	(*RootTree)->Data = 1;
	CreateTwoSubNode(*RootTree);
}

void DestroyBiTree(BiTree *TreeNode)
{
	if (*TreeNode)
	{
		DestroyBiTree(&(*TreeNode)->lChild);
		DestroyBiTree(&(*TreeNode)->rChild);
		free(*TreeNode);
		*TreeNode = NULL;
	}
}

void ShowBiTree(BiTree TreeNode)
{
	if (TreeNode)
	{
		printf("%d", TreeNode->Data);
		if (TreeNode->lChild)
		{
			printf("(");
			ShowBiTree(TreeNode->lChild);
			printf(",");
		}

		if (TreeNode->rChild)
		{
			ShowBiTree(TreeNode->rChild);
			printf(")");
		}
	}
	else
	{
		printf("#");
	}
}

//----------------------NormalTree---------------------------
void CreateTreeRoot(BiTree *RootTree)
{
	*RootTree = (BiTree)malloc(sizeof(BiTNode));
	memset(*RootTree, 0, sizeof(BiTNode));
	(*RootTree)->Data = 1;
}

void DestroyTree(BiTree *TreeNode)
{
	free(*TreeNode);
	*TreeNode = NULL;
}

BiTree IndexOfNode(BiTree TreeNode, int Data)
{
	if (TreeNode->Data = Data)
	{
		return TreeNode;
	}
	IndexOfNode(TreeNode->lChild, Data);
	IndexOfNode(TreeNode->rChild, Data);
}

BiTree AddNode(BiTree ParentNode, int Data)
{
	BiTree TreeNode;
	
	TreeNode = (BiTree)malloc(sizeof(BiTNode));
	memset(TreeNode, 0, sizeof(BiTNode));
	TreeNode->Parent = ParentNode;
	TreeNode->Data = Data;
	return TreeNode;
}

int GetRandNum(int range)
{
	int i;
	struct timeval tpstart;
	
	gettimeofday(&tpstart,NULL);
    srand(tpstart.tv_usec);
	i = rand()%range;
	return i;
}

void BuildTreeNode(BiTree TreeNode)
{	
	int Num, i;
	
	Num = GetRandNum(4);
	for (i=0; i<=Num; i++)
	{
		//AddNode(TreeNode, )
		//if (TreeNode->Data <= 14)
		//{
		//}
		
	}

}

void ClearTreeNode(BiTree RootTree)
{
	
}

void ShowTree(BiTree TreeNode)
{
	
}
