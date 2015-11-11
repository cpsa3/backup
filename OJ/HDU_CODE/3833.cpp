////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-08-08 17:21:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3833
////Problem Title: 
////Run result: Accept
////Run time:2421MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#define MAXN 10005
using namespace std;
int W[MAXN],N;
void Init()
{
	int i,num;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&num);
		W[num]=i;
	}
}
void Solve()
{
	int i,j,k;
	bool ok=false;
	for(i=1;i<=N&&!ok;i++)
	{
		for(j=i+1;j<=N;j++)
		{
			k=2*j-i;
			if(k>N) break;
			if(W[j]>W[i]&&W[j]<W[k]||W[j]>W[k]&&W[j]<W[i])
			{
				ok=true;
				break;
			}
		}
	}
	if(ok) printf("Y\n");
	else printf("N\n");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		Init();
		Solve();
	}
return 0;
}