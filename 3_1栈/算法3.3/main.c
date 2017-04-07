#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Stack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct
{
	short id;
	short PosType;
} MazeElemType;

typedef struct
{
	MazeElemType arr[10][20];
} MazeType;

void CreateMaze(MazeType **Maze)
{
	*Maze = malloc(sizeof(MazeType));
	if (!(*Maze))
		exit(-1);
	memset(*Maze, 0, sizeof(MazeType));
}

void InitMazeFrame(MazeType *Maze)
{
	short i;
	
	for (i = 0; i < 20; i++)
	{
		Maze->arr[0][i].id = i+1;
		Maze->arr[0][i].PosType = 0;
		
		Maze->arr[9][i].id = i+181;
		Maze->arr[9][i].PosType = 0;
	}
	
	for (i = 1; i < 9; i++)
	{
		Maze->arr[i][0].id = i*20+1;
		Maze->arr[i][0].PosType = 0;
		
		Maze->arr[i][19].id = i*20+20;
		Maze->arr[i][19].PosType = 0;
	}
}

void InitMaze(MazeType *Maze)
{
	short i, j;
	
	InitMazeFrame(Maze);
	
	struct timeval tpstart;
	gettimeofday(&tpstart, NULL);
    srand(tpstart.tv_usec);
    
	//srand((unsigned int)time(0));
	
	
	for (i = 1; i < 9; i++)
	{
		for (j = 1; j < 19; j++)	
		{
			Maze->arr[i][j].id = i*20+j+1;
			if ((i == 1) && (j == 1))
				Maze->arr[i][j].PosType = 1;
			else if ((i == 8) && (j == 18))
				Maze->arr[i][j].PosType = 1;
			else
				Maze->arr[i][j].PosType = 1;//rand() % 2;
		}
	}
	
	
	Maze->arr[1][3].PosType = 0;
	Maze->arr[1][9].PosType = 0;
	Maze->arr[1][14].PosType = 0;
	Maze->arr[1][18].PosType = 0;
	
	Maze->arr[2][5].PosType = 0;
	Maze->arr[2][11].PosType = 0;
	Maze->arr[2][16].PosType = 0;
	
	Maze->arr[4][2].PosType = 0;
	Maze->arr[4][6].PosType = 0;
	Maze->arr[4][10].PosType = 0;
	Maze->arr[4][15].PosType = 0;
	
	Maze->arr[5][1].PosType = 0;
	Maze->arr[5][9].PosType = 0;
	Maze->arr[5][2].PosType = 0;
	
	Maze->arr[7][2].PosType = 0;
	Maze->arr[7][16].PosType = 0;
	
	Maze->arr[8][11].PosType = 0;
	Maze->arr[8][14].PosType = 0;
	
	Maze->arr[9][4].PosType = 0;
	Maze->arr[9][14].PosType = 0;
}

void PrintMaze(MazeType *Maze)
{
	short i, j;
	
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 20; j++)
		{
			switch(Maze->arr[i][j].PosType)
			{
				case 0:	
					printf("#");
					break;
				case 1:
					printf(" ");
					break;
				case 2:
					printf("*");
					break;
				case 3:
					printf("!");
					break;
			}
		}
		printf("\n");
	}
}

void OverMaze(MazeType *Maze)
{
	MazeElemType *pMazeElem;
	
	MoveMazeElemType MoveMazeElem;
	MoveMazeElem.i = 1;
	MoveMazeElem.j = 1;
	memset(&MoveMazeElem.w, 1, sizeof(MoveMazeElem.w));
	
	SqStack *Stack;
	CreateStack(&Stack);
	InitStack(Stack);
	//Push(Stack, MoveMazeElem);
	
	short i;
	
	while (1)
	{
		if (MoveMazeElem.w.Forward)
		{
			i = 0;
			pMazeElem = &Maze->arr[MoveMazeElem.i][MoveMazeElem.j+1];
			MoveMazeElem.w.Forward = False;
		}
		else if (MoveMazeElem.w.Down)
		{
			i = 1;
			pMazeElem = &Maze->arr[MoveMazeElem.i+1][MoveMazeElem.j];
			MoveMazeElem.w.Down = False;
		}
		else if (MoveMazeElem.w.Backward)
		{
			i = 2;
			pMazeElem = &Maze->arr[MoveMazeElem.i][MoveMazeElem.j-1];
			MoveMazeElem.w.Backward = False;
		}
		else if (MoveMazeElem.w.Up)
		{
			i = 3;
			pMazeElem = &Maze->arr[MoveMazeElem.i-1][MoveMazeElem.j];
			MoveMazeElem.w.Up = False;
		}
	
		if ((pMazeElem->PosType == 0) || (pMazeElem->PosType == 2))	//墙
		{
			if ((!MoveMazeElem.w.Forward) && (!MoveMazeElem.w.Down) && 
				(!MoveMazeElem.w.Backward) && (!MoveMazeElem.w.Up))
			{
				Pop(Stack, &MoveMazeElem);
				if ((MoveMazeElem.i == 1) && (MoveMazeElem.j == 1))
				{
					printf("迷宫死路！\n");
					break;
				}
			}
		}
		else if (pMazeElem->PosType == 1)	//路
		{
			if ((MoveMazeElem.i == 8) && (MoveMazeElem.j == 18))
			{
				printf("迷宫成功通过！\n");
				break;
			}
			pMazeElem->PosType = 2;
			Push(Stack, MoveMazeElem);
			memset(&MoveMazeElem.w, 1, sizeof(MoveMazeElem.w));
			switch(i)
			{
				case 0:
					++MoveMazeElem.j;
					MoveMazeElem.w.Backward = False;
					break;
				case 1:
					++MoveMazeElem.i;
					MoveMazeElem.w.Up = False;
					break;
				case 2:
					--MoveMazeElem.j;
					MoveMazeElem.w.Forward = False;
					break;
				case 3:
					--MoveMazeElem.i;
					MoveMazeElem.w.Down = False;
					break;
			}
		}
	}
	ClearStack(Stack);
	DestroyStack(&Stack);
}

int main(int argc, char *argv[])
{
	MazeType *Maze;

	CreateMaze(&Maze);
	InitMaze(Maze);
	PrintMaze(Maze);
	system("pause");
	printf("\n");
	OverMaze(Maze);
	PrintMaze(Maze);
	system("pause");
	
	
	
	
	
/*
	SqStack *Stack;
	MoveMazeElemType MoveMazeElem;
	
	CreateStack(&Stack);
	
	InitStack(Stack);
	
	StackEmpty(Stack);
		
	MoveMazeElem.di = 1;
	Push(Stack, MoveMazeElem);
	MoveMazeElem.di = 2;
	Push(Stack, MoveMazeElem);
	memset(&MoveMazeElem, 0, sizeof(MoveMazeElem));
	GetTop(Stack, &MoveMazeElem);
	MoveMazeElem.di = 3;
	Push(Stack, MoveMazeElem);
	
	StackEmpty(Stack);
	
	memset(&MoveMazeElem, 0, sizeof(MoveMazeElem));
	Pop(Stack, &MoveMazeElem);
	memset(&MoveMazeElem, 0, sizeof(MoveMazeElem));
	Pop(Stack, &MoveMazeElem);
	memset(&MoveMazeElem, 0, sizeof(MoveMazeElem));
	GetTop(Stack, &MoveMazeElem);
	memset(&MoveMazeElem, 0, sizeof(MoveMazeElem));
	Pop(Stack, &MoveMazeElem);
	
	StackEmpty(Stack);
	
	ClearStack(Stack);
	
	StackEmpty(Stack);
	
	DestroyStack(&Stack);
*/

	return 0;
}

/**************************************************************************/
/*
int Pass(MazeType *MyMaze, PosType *CurPos)
{
	if (MyMaze->arr[CurPos->r][CurPos->c] == ' ')
		return 1;	//如果当前位置是可以通过,返回 1
	else
		return 0;	//其它情况返回 0
}

void FootPrint(MazeType *MyMaze, PosType *CurPos)
{
	MyMaze->arr[CurPos->r][CurPos->c] = '*';
}

void MarkPrint(MazeType *MyMaze, PosType *CurPos)
{
	MyMaze->arr[CurPos->r][CurPos->c] = '!';
}

void NextPos(PosType *CurPos, int Dir)
{
	switch (Dir)
	{
		case 1:
			++CurPos->c;
			break;
		case 2:
			++CurPos->r;
			break;
		case 3:
			--CurPos->c;
			break;
		case 4:
			--CurPos->r;
			break;
	}
}

Status MazePath(MazeType *maze, PosType *start, PosType *end)
{
	//若迷宫maze中从入口 start到出口 end的通道,则求得一条存放在栈中
	//(从栈底到栈顶),并返回TRUE;否则返回FALSE
	SqStack S;
	PosType curpos;
	int curstep;
	SElemType e;

	InitStack(&S);
	curpos = *start;  // 设定"当前位置"为"入口位置"
	curstep = 1;     // 探索第一步
	do
	{
		if (Pass(maze, &curpos))    // 当前位置可通过，即是未曾走到过的通道块
		{
			FootPrint(maze, &curpos); // 留下足迹
			e.di = 1;
			e.ord = curstep;
			e.seat = curpos;
			Push(S, e);              // 加入路径
			if (curpos.r == end->r && curpos.c == end->c)
				return (TRUE);        // 到达终点（出口）
			curpos = NextPos(curpos, 1);        // 下一位置是当前位置的东邻
			curstep++;                          // 探索下一步
		}
		else      // 当前位置不能通过
		{
			if (!StackEmpty(S))
			{
				Pop(S,e);
				while (e.di==4 && !StackEmpty(S))
				{
					MarkPrint(maze,e.seat);
					Pop(S,e);    // 留下不能通过的标记，并退回一步
				}
				if (e.di<4)
				{
					e.di++;
					Push(S, e);  // 换下一个方向探索
					curpos = NextPos(e.seat, e.di); // 当前位置设为新方向的相邻块
				}
			}
		}
	}
	while (!StackEmpty(S) );
	return FALSE;
}

*/
