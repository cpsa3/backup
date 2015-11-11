////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___¼òÑÔ
////Run ID: 
////Submit time: 2011-08-09 17:28:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3866
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:380KB
//////////////////System Comment End//////////////////
/*Ì°ÐÄ*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#define MAXN 1000005
using namespace std;
struct Node
{
	int a,b,id;
}node[MAXN];
int P,N;
__int64 Sum;
int ans[MAXN];
int cmp(const void *p1,const void *p2)
{
	if(((struct Node *)p1)->a!=((struct Node *)p2)->a)
		return ((struct Node *)p1)->a-((struct Node *)p2)->a;
	return ((struct Node *)p2)->id-((struct Node *)p1)->id;
}

void Init()
{
	int i;
	Sum=0;
	scanf("%d%d",&P,&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&node[i].a);
		node[i].id=i;
		Sum+=node[i].a;
	}
	qsort(node+1,N,sizeof(node[0]),cmp);
}
void Solve()
{
	int i;
	__int64 now=P;
	if(Sum<P)
	{printf("IMPOSSIBLE\n");return;}
	for(i=1;i<=N;i++)
	{
		__int64 t=now/(N-i+1);
		if(node[i].a<=t)
		{
			now-=node[i].a;
			ans[node[i].id]=node[i].a;
		}
		else
		{
			now-=t;
			ans[node[i].id]=t;
		}
	}
	for(i=1;i<N;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[i]);
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