////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-09 17:26:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3864
////Problem Title: 
////Run result: Accept
////Run time:453MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*分解质因数*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define MAXN 5000005
using namespace std;
__int64 N;
void Run()
{
	int i;
	__int64 p;
	int cnt=0;
	for(i=2;i<=MAXN&&i*i<=N;i++)
	{
		if(N%i==0)
		{
			if(i*i==N) cnt++;
			else cnt+=2;
			p=i;
			if(cnt>2) break;
		}
	}
	if(cnt==2)
		printf("%I64d %I64d %I64d\n",p,N/p,N);
	else
		printf("is not a D_num\n");
}
int main()
{
	while(scanf("%I64d",&N)!=EOF)
	{
		if(N==1||N==2||N==3||N==4)
		{printf("is not a D_num\n");continue;}
		Run();
	}
return 0;
}