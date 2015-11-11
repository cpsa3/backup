////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-05-02 23:44:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2601
////Problem Title: 
////Run result: Accept
////Run time:1687MS
////Run memory:236KB
//////////////////System Comment End//////////////////
/*Ä£Äâ*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
int main()
{
	int T,i;
	__int64 N;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d",&N);
		N++;
		__int64 mid=sqrt((double)(N))-1,ans=0;
		for(i=1;i<=mid;i++)
		{
			if(N%(i+1)==0)
				ans++; 
		}
		printf("%I64d\n",ans); 
	}
return 0;
}