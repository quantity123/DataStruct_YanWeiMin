// 算法时间复杂度.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <time.h>
#include <windows.h>
#include <Winsock2.h>

void DataTypeLen()
{
	printf("char=%d\n",sizeof(char));
	printf("short=%d\n",sizeof(short));
    printf("int=%d\n",sizeof(int));
    printf("long=%d\n",sizeof(long));
    printf("float=%d\n",sizeof(float));
    printf("double=%d\n",sizeof(double));
}

int gettimeofday(struct timeval *tp, void *tzp)
{
    time_t clock;
    struct tm tm;
    SYSTEMTIME wtm;

    GetLocalTime(&wtm);
    tm.tm_year     = wtm.wYear - 1900;
    tm.tm_mon     = wtm.wMonth - 1;
    tm.tm_mday     = wtm.wDay;
    tm.tm_hour     = wtm.wHour;
    tm.tm_min     = wtm.wMinute;
    tm.tm_sec     = wtm.wSecond;
    tm. tm_isdst    = -1;
    clock = mktime(&tm);
    tp->tv_sec = clock;
    tp->tv_usec = wtm.wMilliseconds * 1000;

    return (0);
}

void f1(long n)
{
	short x = 0;
	long s = 0;
	++x;
	s += x;
}

void f2(long n)
{
	short x = 0;
	long s = 0;
	int i;
	for (i = 1; i <= n; i++)
	{
		++x;
		s += x;
	}	
}

long f3(long n)
{
	short x = 0;
	long s = 0;
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			++x;
			s += x;
		}
	}
	return s;
}

int main(int argc, char* argv[])
{
	//DataTypeLen();
	time_t start, ends;
	clock_t cstart, cends;
	//struct timeval tv_start, tv_ends;

	start = time(NULL);
	cstart = clock();
	//gettimeofday(&tv_start, NULL);
	unsigned long dwBeginTime = GetTickCount();

	//f1();
	//f2(900000);
	f3(50000);
	//Sleep(2000);

	ends = time(NULL);
	cends = clock();
	//gettimeofday(&tv_ends, NULL);
	unsigned long dwEndTime = GetTickCount();


	printf("time:%d\n", ends-start);
	printf("clock:%d\n", cends-cstart);
	printf("GetTickCount:%d\n", (dwEndTime - dwBeginTime) / 1000);
	return 0;
}

